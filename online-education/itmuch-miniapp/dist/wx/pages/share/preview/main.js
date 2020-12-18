require("../../../common/manifest.js");
require("../../../common/vendor.js");
global.webpackJsonp([7],{

/***/ 188:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
Object.defineProperty(__webpack_exports__, "__esModule", { value: true });
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_vue__ = __webpack_require__(4);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_vue___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_0_vue__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__index__ = __webpack_require__(189);



var app = new __WEBPACK_IMPORTED_MODULE_0_vue___default.a(__WEBPACK_IMPORTED_MODULE_1__index__["a" /* default */]);
app.$mount();

/***/ }),

/***/ 189:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__babel_loader_node_modules_mpvue_loader_lib_selector_type_script_index_0_index_vue__ = __webpack_require__(191);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__node_modules_mpvue_loader_lib_template_compiler_index_id_data_v_08e2978e_hasScoped_false_transformToRequire_video_src_source_src_img_src_image_xlink_href_node_modules_mpvue_loader_lib_selector_type_template_index_0_index_vue__ = __webpack_require__(192);
var disposed = false
function injectStyle (ssrContext) {
  if (disposed) return
  __webpack_require__(190)
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
  __WEBPACK_IMPORTED_MODULE_1__node_modules_mpvue_loader_lib_template_compiler_index_id_data_v_08e2978e_hasScoped_false_transformToRequire_video_src_source_src_img_src_image_xlink_href_node_modules_mpvue_loader_lib_selector_type_template_index_0_index_vue__["a" /* default */],
  __vue_styles__,
  __vue_scopeId__,
  __vue_module_identifier__
)
Component.options.__file = "src/pages/share/preview/index.vue"
if (Component.esModule && Object.keys(Component.esModule).some(function (key) {return key !== "default" && key.substr(0, 2) !== "__"})) {console.error("named exports are not supported in *.vue files.")}
if (Component.options.functional) {console.error("[vue-loader] index.vue: functional components are not supported with templates, they should use render functions.")}

/* hot reload */
if (false) {(function () {
  var hotAPI = require("vue-hot-reload-api")
  hotAPI.install(require("vue"), false)
  if (!hotAPI.compatible) return
  module.hot.accept()
  if (!module.hot.data) {
    hotAPI.createRecord("data-v-08e2978e", Component.options)
  } else {
    hotAPI.reload("data-v-08e2978e", Component.options)
  }
  module.hot.dispose(function (data) {
    disposed = true
  })
})()}

/* harmony default export */ __webpack_exports__["a"] = (Component.exports);


/***/ }),

/***/ 190:
/***/ (function(module, exports) {

// removed by extract-text-webpack-plugin

/***/ }),

/***/ 191:
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
                return Object(__WEBPACK_IMPORTED_MODULE_2__utils_request__["a" /* request */])(__WEBPACK_IMPORTED_MODULE_3__utils_api__["f" /* SHARE_POST_PREVIEW_URL */] + ('/' + id), 'GET', {});

              case 3:
                _this.share = _context.sent;
                summary = _this.share.summary;

                _this.summary = __WEBPACK_IMPORTED_MODULE_5_marked___default()(summary);

              case 6:
              case 'end':
                return _context.stop();
            }
          }
        }, _callee, _this);
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

/***/ 192:
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
    staticClass: "download"
  }, [_c('h3', [_vm._v("下载地址")]), _vm._v(" "), _c('div', [_vm._v(_vm._s(_vm.share.downloadUrl))])], 1)])
}
var staticRenderFns = []
render._withStripped = true
var esExports = { render: render, staticRenderFns: staticRenderFns }
/* harmony default export */ __webpack_exports__["a"] = (esExports);
if (false) {
  module.hot.accept()
  if (module.hot.data) {
     require("vue-hot-reload-api").rerender("data-v-08e2978e", esExports)
  }
}

/***/ })

},[188]);
//# sourceMappingURL=main.js.map