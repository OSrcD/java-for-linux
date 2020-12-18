const path = require('path');
const upath = require('upath');
const relative = require('relative');

function MpvuePlugin() {}

MpvuePlugin.prototype.apply = function(compiler) {
  compiler.plugin('emit', function(compilation, callback) {
    Object.keys(compilation.entrypoints).forEach(key => {
      const entry = compilation.entrypoints[key];
      const { chunks } = entry;
      const entryChunk = chunks.pop();
      entryChunk.files.forEach(filePath => {
        const extname = path.extname(filePath);
        let content = compilation.assets[filePath].source();
        chunks.reverse().forEach(chunk => {
          chunk.files.forEach(childFile => {
            if (path.extname(childFile) === extname && compilation.assets[filePath]) {
              let relativePath = upath.normalize(relative(filePath, childFile))

              // 百度小程序js引用不支持绝对路径，改为相对路径
              if (extname === '.js' && !/^\.(\.)?\//.test(relativePath)) {
                relativePath = `./${relativePath}`;
              }

              if (/^(\.wxss)|(\.css)$/.test(extname)) {
                content = `@import "${relativePath}";\n${content}`;
              } else {
                content = `require("${relativePath}");\n${content}`;
              }
            }
          })
          compilation.assets[filePath].source = () => content;
        })
      })
    })
    callback();
  });
};

module.exports = MpvuePlugin;
