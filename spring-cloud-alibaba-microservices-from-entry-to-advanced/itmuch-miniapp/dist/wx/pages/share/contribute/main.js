require("../../../common/manifest.js");
require("../../../common/vendor.js");
global.webpackJsonp([9],{

/***/ 106:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
Object.defineProperty(__webpack_exports__, "__esModule", { value: true });
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_vue__ = __webpack_require__(4);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_vue___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_0_vue__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__index__ = __webpack_require__(107);



var app = new __WEBPACK_IMPORTED_MODULE_0_vue___default.a(__WEBPACK_IMPORTED_MODULE_1__index__["a" /* default */]);
app.$mount();

/***/ }),

/***/ 107:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__babel_loader_node_modules_mpvue_loader_lib_selector_type_script_index_0_index_vue__ = __webpack_require__(109);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__node_modules_mpvue_loader_lib_template_compiler_index_id_data_v_0e9fb39c_hasScoped_true_transformToRequire_video_src_source_src_img_src_image_xlink_href_node_modules_mpvue_loader_lib_selector_type_template_index_0_index_vue__ = __webpack_require__(110);
var disposed = false
function injectStyle (ssrContext) {
  if (disposed) return
  __webpack_require__(108)
}
var normalizeComponent = __webpack_require__(0)
/* script */

/* template */

/* styles */
var __vue_styles__ = injectStyle
/* scopeId */
var __vue_scopeId__ = "data-v-0e9fb39c"
/* moduleIdentifier (server only) */
var __vue_module_identifier__ = null
var Component = normalizeComponent(
  __WEBPACK_IMPORTED_MODULE_0__babel_loader_node_modules_mpvue_loader_lib_selector_type_script_index_0_index_vue__["a" /* default */],
  __WEBPACK_IMPORTED_MODULE_1__node_modules_mpvue_loader_lib_template_compiler_index_id_data_v_0e9fb39c_hasScoped_true_transformToRequire_video_src_source_src_img_src_image_xlink_href_node_modules_mpvue_loader_lib_selector_type_template_index_0_index_vue__["a" /* default */],
  __vue_styles__,
  __vue_scopeId__,
  __vue_module_identifier__
)
Component.options.__file = "src/pages/share/contribute/index.vue"
if (Component.esModule && Object.keys(Component.esModule).some(function (key) {return key !== "default" && key.substr(0, 2) !== "__"})) {console.error("named exports are not supported in *.vue files.")}
if (Component.options.functional) {console.error("[vue-loader] index.vue: functional components are not supported with templates, they should use render functions.")}

/* hot reload */
if (false) {(function () {
  var hotAPI = require("vue-hot-reload-api")
  hotAPI.install(require("vue"), false)
  if (!hotAPI.compatible) return
  module.hot.accept()
  if (!module.hot.data) {
    hotAPI.createRecord("data-v-0e9fb39c", Component.options)
  } else {
    hotAPI.reload("data-v-0e9fb39c", Component.options)
  }
  module.hot.dispose(function (data) {
    disposed = true
  })
})()}

/* harmony default export */ __webpack_exports__["a"] = (Component.exports);


/***/ }),

/***/ 108:
/***/ (function(module, exports) {

// removed by extract-text-webpack-plugin

/***/ }),

/***/ 109:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator__ = __webpack_require__(5);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_babel_runtime_helpers_asyncToGenerator__ = __webpack_require__(6);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_babel_runtime_helpers_asyncToGenerator___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_1_babel_runtime_helpers_asyncToGenerator__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2__utils_request__ = __webpack_require__(2);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3__utils_api__ = __webpack_require__(1);


//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//




/* harmony default export */ __webpack_exports__["a"] = ({
  data: function data() {
    return {
      isOriginal: 'true',
      title: '',
      author: '',
      price: '',
      summary: '',
      downloadUrl: ''
    };
  },

  methods: {
    onIsOriginalClick: function onIsOriginalClick(event) {
      this.isOriginal = event.mp.currentTarget.dataset.name;
    },
    onTitleChange: function onTitleChange(event) {
      this.title = event.mp.detail;
    },
    onAuthorChange: function onAuthorChange(event) {
      this.author = event.mp.detail;
    },
    onPriceChange: function onPriceChange(event) {
      this.price = event.mp.detail;
    },
    onSummaryChange: function onSummaryChange(event) {
      this.summary = event.mp.detail;
    },
    onDownloadUrlChange: function onDownloadUrlChange(event) {
      this.downloadUrl = event.mp.detail;
    },
    submit: function submit() {
      var _this = this;

      return __WEBPACK_IMPORTED_MODULE_1_babel_runtime_helpers_asyncToGenerator___default()( /*#__PURE__*/__WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator___default.a.mark(function _callee() {
        var post, thus;
        return __WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator___default.a.wrap(function _callee$(_context) {
          while (1) {
            switch (_context.prev = _context.next) {
              case 0:
                _context.next = 2;
                return Object(__WEBPACK_IMPORTED_MODULE_2__utils_request__["a" /* request */])(__WEBPACK_IMPORTED_MODULE_3__utils_api__["e" /* SHARE_POST_CONTRIBUTE_URL */], 'POST', {
                  isOriginal: _this.isOriginal,
                  title: _this.title,
                  author: _this.author,
                  price: _this.price,
                  summary: _this.summary,
                  downloadUrl: _this.downloadUrl
                });

              case 2:
                post = _context.sent;
                thus = _this;

                wx.showModal({
                  title: '提示',
                  content: '投稿成功，将在最快是速度审核资源！',
                  cancelText: '继续投稿',
                  confirmText: '前往预览',
                  success: function success(res) {
                    thus.isOriginal = 'false';
                    thus.title = '';
                    thus.author = '';
                    thus.price = '';
                    thus.summary = '';
                    thus.downloadUrl = '';
                    if (res.confirm) {
                      var id = post.id;
                      wx.navigateTo({
                        url: '/pages/share/preview/main?id=' + id
                      });
                    }
                  }
                });

              case 5:
              case 'end':
                return _context.stop();
            }
          }
        }, _callee, _this);
      }))();
    }
  }
});

/***/ }),

/***/ 110:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
var render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;
  return _c('div', [_c('div', {
    staticClass: "description"
  }, [_vm._v("\n    说明：投稿审核通过后会有积分奖励；资源被下载会有积分奖励；提交的资源不得包含广告、侵权信息，百度盘地址建议有密码。\n  ")]), _vm._v(" "), _c('van-radio-group', {
    attrs: {
      "eventid": '2',
      "mpcomid": '5'
    },
    model: {
      value: (_vm.isOriginal),
      callback: function($$v) {
        _vm.isOriginal = $$v
      },
      expression: "isOriginal"
    }
  }, [_c('van-cell-group', {
    attrs: {
      "mpcomid": '4'
    }
  }, [_c('van-cell', {
    attrs: {
      "title": "原创",
      "clickable": "",
      "data-name": "true",
      "eventid": '0',
      "mpcomid": '1'
    },
    on: {
      "click": _vm.onIsOriginalClick
    }
  }, [_c('van-radio', {
    attrs: {
      "name": "true",
      "mpcomid": '0'
    }
  })], 1), _vm._v(" "), _c('van-cell', {
    attrs: {
      "title": "转载",
      "clickable": "",
      "data-name": "false",
      "eventid": '1',
      "mpcomid": '3'
    },
    on: {
      "click": _vm.onIsOriginalClick
    }
  }, [_c('van-radio', {
    attrs: {
      "name": "false",
      "mpcomid": '2'
    }
  })], 1)], 1)], 1), _vm._v(" "), _c('van-cell-group', {
    attrs: {
      "mpcomid": '11'
    }
  }, [_c('van-field', {
    attrs: {
      "clearable": "",
      "label": "标题",
      "placeholder": "请输入标题",
      "eventid": '3',
      "mpcomid": '6'
    },
    on: {
      "change": _vm.onTitleChange
    },
    model: {
      value: (_vm.title),
      callback: function($$v) {
        _vm.title = $$v
      },
      expression: "title"
    }
  }), _vm._v(" "), _c('van-field', {
    attrs: {
      "clearable": "",
      "label": "作者",
      "placeholder": "请输入作者",
      "eventid": '4',
      "mpcomid": '7'
    },
    on: {
      "change": _vm.onAuthorChange
    },
    model: {
      value: (_vm.author),
      callback: function($$v) {
        _vm.author = $$v
      },
      expression: "author"
    }
  }), _vm._v(" "), _c('van-field', {
    attrs: {
      "clearable": "",
      "type": "number",
      "label": "价格",
      "placeholder": "请输入价格",
      "eventid": '5',
      "mpcomid": '8'
    },
    on: {
      "change": _vm.onPriceChange
    },
    model: {
      value: (_vm.price),
      callback: function($$v) {
        _vm.price = $$v
      },
      expression: "price"
    }
  }), _vm._v(" "), _c('van-field', {
    attrs: {
      "clearable": "",
      "type": "textarea",
      "autosize": "true",
      "label": "简介",
      "placeholder": "介绍一下技术干货吧",
      "eventid": '6',
      "mpcomid": '9'
    },
    on: {
      "change": _vm.onSummaryChange
    },
    model: {
      value: (_vm.summary),
      callback: function($$v) {
        _vm.summary = $$v
      },
      expression: "summary"
    }
  }), _vm._v(" "), _c('van-field', {
    attrs: {
      "clearable": "",
      "type": "textarea",
      "autosize": "true",
      "label": "下载地址",
      "placeholder": "请输入下载地址",
      "eventid": '7',
      "mpcomid": '10'
    },
    on: {
      "change": _vm.onDownloadUrlChange
    },
    model: {
      value: (_vm.downloadUrl),
      callback: function($$v) {
        _vm.downloadUrl = $$v
      },
      expression: "downloadUrl"
    }
  })], 1), _vm._v(" "), _c('van-button', {
    attrs: {
      "type": "danger",
      "size": "large",
      "eventid": '8',
      "mpcomid": '12'
    },
    on: {
      "click": _vm.submit
    }
  }, [_vm._v("提交")])], 1)
}
var staticRenderFns = []
render._withStripped = true
var esExports = { render: render, staticRenderFns: staticRenderFns }
/* harmony default export */ __webpack_exports__["a"] = (esExports);
if (false) {
  module.hot.accept()
  if (module.hot.data) {
     require("vue-hot-reload-api").rerender("data-v-0e9fb39c", esExports)
  }
}

/***/ })

},[106]);
//# sourceMappingURL=main.js.map