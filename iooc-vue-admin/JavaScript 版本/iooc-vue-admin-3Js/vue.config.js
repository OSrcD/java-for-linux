const isProduction = process.env.NODE_ENV === "production";

module.exports = {
    publicPath: "/",
    lintOnSave: false,
    productionSourceMap: false,
    parallel: require("os").cpus().length > 1,

    css: {
        extract: isProduction,
        sourceMap: false,
        loaderOptions: {
            sass: {
                prependData: `@import "~@/assets/css/common.scss";`,
            }
        }
    },

    devServer: {
        port: 9000,
        open: false,
        compress: false,
        overlay: {
            warnings: false,
            errors: true
        },

        proxy: {
            "/dev": {
                target: "http://49.232.210.33:7003",
                changeOrigin: true,
                pathRewrite: {
                    "^/dev": ""
                }
            },

            "/oss-upload": {
                target: "https://vue3-element-admin.oss-cn-beijing.aliyuncs.com",
                changeOrigin: true,
                pathRewrite: {
                    "^/oss-upload": ""
                }
            },
        }
    },

    chainWebpack: config => {
        // Svg rules
        const svgRule = config.module.rule("svg");

        svgRule.uses.clear();
        svgRule
            .use("svg-sprite-loader")
            .loader("svg-sprite-loader")
            .options({
                symbolId: "[name]"
            })
            .end();

        if (isProduction) {
            config.performance.set("hints", false);
        }
    }
};
