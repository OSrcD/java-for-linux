require("../../../common/manifest.js");
require("../../../common/vendor.js");
global.webpackJsonp([8],{

/***/ 111:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
Object.defineProperty(__webpack_exports__, "__esModule", { value: true });
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_vue__ = __webpack_require__(4);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_vue___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_0_vue__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__index__ = __webpack_require__(112);



var app = new __WEBPACK_IMPORTED_MODULE_0_vue___default.a(__WEBPACK_IMPORTED_MODULE_1__index__["a" /* default */]);
app.$mount();

/***/ }),

/***/ 112:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__babel_loader_node_modules_mpvue_loader_lib_selector_type_script_index_0_index_vue__ = __webpack_require__(114);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__node_modules_mpvue_loader_lib_template_compiler_index_id_data_v_e1f06fd4_hasScoped_false_transformToRequire_video_src_source_src_img_src_image_xlink_href_node_modules_mpvue_loader_lib_selector_type_template_index_0_index_vue__ = __webpack_require__(178);
var disposed = false
function injectStyle (ssrContext) {
  if (disposed) return
  __webpack_require__(113)
}
var normalizeComponent = __webpack_require__(0)
/* script */

/* template */

/* styles */
var __vue_styles__ = injectStyle
/* scopeId */
var __vue_scopeId__ = null
/* moduleIdentifier (server only) */
var __vue_module_identifier__ = null
var Component = normalizeComponent(
  __WEBPACK_IMPORTED_MODULE_0__babel_loader_node_modules_mpvue_loader_lib_selector_type_script_index_0_index_vue__["a" /* default */],
  __WEBPACK_IMPORTED_MODULE_1__node_modules_mpvue_loader_lib_template_compiler_index_id_data_v_e1f06fd4_hasScoped_false_transformToRequire_video_src_source_src_img_src_image_xlink_href_node_modules_mpvue_loader_lib_selector_type_template_index_0_index_vue__["a" /* default */],
  __vue_styles__,
  __vue_scopeId__,
  __vue_module_identifier__
)
Component.options.__file = "src/pages/share/detail/index.vue"
if (Component.esModule && Object.keys(Component.esModule).some(function (key) {return key !== "default" && key.substr(0, 2) !== "__"})) {console.error("named exports are not supported in *.vue files.")}
if (Component.options.functional) {console.error("[vue-loader] index.vue: functional components are not supported with templates, they should use render functions.")}

/* hot reload */
if (false) {(function () {
  var hotAPI = require("vue-hot-reload-api")
  hotAPI.install(require("vue"), false)
  if (!hotAPI.compatible) return
  module.hot.accept()
  if (!module.hot.data) {
    hotAPI.createRecord("data-v-e1f06fd4", Component.options)
  } else {
    hotAPI.reload("data-v-e1f06fd4", Component.options)
  }
  module.hot.dispose(function (data) {
    disposed = true
  })
})()}

/* harmony default export */ __webpack_exports__["a"] = (Component.exports);


/***/ }),

/***/ 113:
/***/ (function(module, exports) {

// removed by extract-text-webpack-plugin

/***/ }),

/***/ 114:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator__ = __webpack_require__(5);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_babel_runtime_helpers_asyncToGenerator__ = __webpack_require__(6);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_babel_runtime_helpers_asyncToGenerator___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_1_babel_runtime_helpers_asyncToGenerator__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2__utils_request__ = __webpack_require__(2);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3__utils_api__ = __webpack_require__(1);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_4_mpvue_wxparse__ = __webpack_require__(49);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_5_marked__ = __webpack_require__(50);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_5_marked___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_5_marked__);


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
  components: {
    wxParse: __WEBPACK_IMPORTED_MODULE_4_mpvue_wxparse__["a" /* default */]
  },
  data: function data() {
    return {
      share: '',
      id: '',
      summary: ''
    };
  },


  methods: {
    preview: function preview(src, e) {
      // do something
    },
    navigate: function navigate(href, e) {
      // do something
    },
    fetchSharePostById: function fetchSharePostById() {
      var _this = this;

      return __WEBPACK_IMPORTED_MODULE_1_babel_runtime_helpers_asyncToGenerator___default()( /*#__PURE__*/__WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator___default.a.mark(function _callee() {
        var id, summary;
        return __WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator___default.a.wrap(function _callee$(_context) {
          while (1) {
            switch (_context.prev = _context.next) {
              case 0:
                id = _this.id;
                _context.next = 3;
                return Object(__WEBPACK_IMPORTED_MODULE_2__utils_request__["a" /* request */])(__WEBPACK_IMPORTED_MODULE_3__utils_api__["g" /* SHARE_POST_URL */] + ('/' + id), 'GET', {});

              case 3:
                _this.share = _context.sent;
                summary = _this.share.summary;

                console.log('summary', summary);
                _this.summary = __WEBPACK_IMPORTED_MODULE_5_marked___default()(summary);

              case 7:
              case 'end':
                return _context.stop();
            }
          }
        }, _callee, _this);
      }))();
    },
    buy: function buy() {
      var _this2 = this;

      return __WEBPACK_IMPORTED_MODULE_1_babel_runtime_helpers_asyncToGenerator___default()( /*#__PURE__*/__WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator___default.a.mark(function _callee2() {
        var id;
        return __WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator___default.a.wrap(function _callee2$(_context2) {
          while (1) {
            switch (_context2.prev = _context2.next) {
              case 0:
                id = _this2.id;
                _context2.next = 3;
                return Object(__WEBPACK_IMPORTED_MODULE_2__utils_request__["a" /* request */])(__WEBPACK_IMPORTED_MODULE_3__utils_api__["g" /* SHARE_POST_URL */] + ('/exchange/' + id), 'GET', {});

              case 3:
                wx.navigateTo({
                  url: '/pages/share/buy-success/main?id=' + id
                });

              case 4:
              case 'end':
                return _context2.stop();
            }
          }
        }, _callee2, _this2);
      }))();
    }
  },
  onLoad: function onLoad() {
    this.id = this.$root.$mp.query.id;
    console.log('detail', this.id);
    this.fetchSharePostById();
  }
});

/***/ }),

/***/ 178:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
var render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;
  return _c('div', {
    staticClass: "detail-wrapper"
  }, [_c('div', {
    staticClass: "detail-header"
  }, [_c('h1', {
    staticClass: "title"
  }, [_vm._v(_vm._s(_vm.share.title))]), _vm._v(" "), _c('div', {
    staticClass: "intro"
  }, [_c('div', {
    staticClass: "author"
  }, [_vm._v("作者：" + _vm._s(_vm.share.author))]), _vm._v(" "), _c('div', {
    staticClass: "author"
  }, [_vm._v("发布人：" + _vm._s(_vm.share.username))]), _vm._v(" "), _c('div', {
    staticClass: "count"
  }, [_vm._v("下载数：" + _vm._s(_vm.share.buyCount))])])], 1), _vm._v(" "), _c('div', {
    staticClass: "content"
  }, [_c('wxParse', {
    attrs: {
      "content": _vm.summary,
      "eventid": '0',
      "mpcomid": '0'
    },
    on: {
      "preview": _vm.preview,
      "navigate": _vm.navigate
    }
  })], 1), _vm._v(" "), _c('div', {
    slot: "footer"
  }, [_c('van-submit-bar', {
    attrs: {
      "price": _vm.share.price * 100,
      "label": "积分",
      "button-text": "兑换",
      "currency": "฿",
      "eventid": '1',
      "mpcomid": '1'
    },
    on: {
      "click": function($event) {
        _vm.buy()
      }
    }
  })], 1), _vm._v(" "), _c('van-toast', {
    attrs: {
      "id": "van-toast",
      "mpcomid": '2'
    }
  })], 1)
}
var staticRenderFns = []
render._withStripped = true
var esExports = { render: render, staticRenderFns: staticRenderFns }
/* harmony default export */ __webpack_exports__["a"] = (esExports);
if (false) {
  module.hot.accept()
  if (module.hot.data) {
     require("vue-hot-reload-api").rerender("data-v-e1f06fd4", esExports)
  }
}

/***/ })

},[111]);
//# sourceMappingURL=main.js.map