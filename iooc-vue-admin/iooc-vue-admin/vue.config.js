const path = require('path')

function resolve(dir) {
    return path.join(__dirname, dir)
}

module.exports = {
    devServer: {
		port: 8889,
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
    configureWebpack: {
        resolve: {
            //路径别名配置
            alias: {
                '@': resolve('src'),
                'assets': resolve('@/assets'),
                'common': resolve('@/common'),
                'components': resolve('@/components'),
                'network': resolve('@/network'),
                'views': resolve('@/views'),
            }
        }
    },
    css: {
        loaderOptions: {
            scss: {
                prependData: `@import "~@/assets/css/common.scss";`,
            },
        }
    },
    productionSourceMap: false,
    publicPath: "/",
    lintOnSave: false, // 临时关闭eslint
    chainWebpack: (config) => {
        //配置 svg-sprite-loader
        // 第一步：让其他svg loader不要对src/icons进行操作
        config.module
            .rule('svg')
            .exclude.add(resolve('src/icons/svg'))//注意：路径要具体到存放的svg的路径下，不然会报错
            .end()
        // 第二步：使用svg-sprite-loader 对 src/icons下的svg进行操作
        config.module
            .rule('icons')
            .test(/\.svg$/)
            .include.add(resolve('src/icons/svg'))//注意：路径要具体到存放的svg的路径下，不然会报错
            .end()
            .use('svg-sprite-loader')
            .loader('svg-sprite-loader')
            //定义规则 使用时 <icon-svg class="icon"> <use xlink:href="#icon-svg文件名"></use>  </svg>
            .options({
                symbolId: '[name]'
            })
            .end()
    }
}
