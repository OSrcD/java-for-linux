require("../../../common/manifest.js");
require("../../../common/vendor.js");
global.webpackJsonp([5],{

/***/ 198:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
Object.defineProperty(__webpack_exports__, "__esModule", { value: true });
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_vue__ = __webpack_require__(4);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_vue___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_0_vue__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__index__ = __webpack_require__(199);



var app = new __WEBPACK_IMPORTED_MODULE_0_vue___default.a(__WEBPACK_IMPORTED_MODULE_1__index__["a" /* default */]);
app.$mount();

/***/ }),

/***/ 199:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__babel_loader_node_modules_mpvue_loader_lib_selector_type_script_index_0_index_vue__ = __webpack_require__(201);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__node_modules_mpvue_loader_lib_template_compiler_index_id_data_v_af62d944_hasScoped_false_transformToRequire_video_src_source_src_img_src_image_xlink_href_node_modules_mpvue_loader_lib_selector_type_template_index_0_index_vue__ = __webpack_require__(202);
var disposed = false
function injectStyle (ssrContext) {
  if (disposed) return
  __webpack_require__(200)
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
  __WEBPACK_IMPORTED_MODULE_1__node_modules_mpvue_loader_lib_template_compiler_index_id_data_v_af62d944_hasScoped_false_transformToRequire_video_src_source_src_img_src_image_xlink_href_node_modules_mpvue_loader_lib_selector_type_template_index_0_index_vue__["a" /* default */],
  __vue_styles__,
  __vue_scopeId__,
  __vue_module_identifier__
)
Component.options.__file = "src/pages/user/complete/index.vue"
if (Component.esModule && Object.keys(Component.esModule).some(function (key) {return key !== "default" && key.substr(0, 2) !== "__"})) {console.error("named exports are not supported in *.vue files.")}
if (Component.options.functional) {console.error("[vue-loader] index.vue: functional components are not supported with templates, they should use render functions.")}

/* hot reload */
if (false) {(function () {
  var hotAPI = require("vue-hot-reload-api")
  hotAPI.install(require("vue"), false)
  if (!hotAPI.compatible) return
  module.hot.accept()
  if (!module.hot.data) {
    hotAPI.createRecord("data-v-af62d944", Component.options)
  } else {
    hotAPI.reload("data-v-af62d944", Component.options)
  }
  module.hot.dispose(function (data) {
    disposed = true
  })
})()}

/* harmony default export */ __webpack_exports__["a"] = (Component.exports);


/***/ }),

/***/ 200:
/***/ (function(module, exports) {

// removed by extract-text-webpack-plugin

/***/ }),

/***/ 201:
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




/* harmony default export */ __webpack_exports__["a"] = ({
  data: function data() {
    return {
      nickname: '',
      mobile: '',
      email: '',
      address: ''
    };
  },

  methods: {
    onNicknameChange: function onNicknameChange(event) {
      this.nickname = event.mp.detail;
    },
    onMobileChange: function onMobileChange(event) {
      this.mobile = event.mp.detail;
    },
    onEmailChange: function onEmailChange(event) {
      this.email = event.mp.detail;
    },
    onAddressChange: function onAddressChange(event) {
      this.address = event.mp.detail;
    },
    getUserData: function getUserData() {
      var _this = this;

      return __WEBPACK_IMPORTED_MODULE_1_babel_runtime_helpers_asyncToGenerator___default()( /*#__PURE__*/__WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator___default.a.mark(function _callee() {
        var user;
        return __WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator___default.a.wrap(function _callee$(_context) {
          while (1) {
            switch (_context.prev = _context.next) {
              case 0:
                _context.next = 2;
                return Object(__WEBPACK_IMPORTED_MODULE_2__utils_request__["a" /* request */])(__WEBPACK_IMPORTED_MODULE_3__utils_api__["l" /* USER_URL_ME */], 'GET', {});

              case 2:
                user = _context.sent;

                _this.nickname = user.nickname;
                _this.mobile = user.mobile;
                _this.email = user.email;
                _this.address = user.address;

              case 7:
              case "end":
                return _context.stop();
            }
          }
        }, _callee, _this);
      }))();
    },
    submit: function submit() {
      Object(__WEBPACK_IMPORTED_MODULE_2__utils_request__["a" /* request */])(__WEBPACK_IMPORTED_MODULE_3__utils_api__["k" /* USER_URL_COMPLETE */], 'PUT', {
        nickname: this.nickname,
        mobile: this.mobile,
        email: this.email,
        address: this.address
      }).then(function (res) {
        wx.showToast({
          title: '修改成功'
        });
      });
    }
  },
  onLoad: function onLoad() {
    this.getUserData();
  }
});

/***/ }),

/***/ 202:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
var render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;
  return _c('div', [_c('van-cell-group', {
    attrs: {
      "mpcomid": '4'
    }
  }, [_c('van-field', {
    attrs: {
      "clearable": "",
      "label": "昵称",
      "placeholder": "请输入昵称",
      "eventid": '0',
      "mpcomid": '0'
    },
    on: {
      "change": _vm.onNicknameChange
    },
    model: {
      value: (_vm.nickname),
      callback: function($$v) {
        _vm.nickname = $$v
      },
      expression: "nickname"
    }
  }), _vm._v(" "), _c('van-field', {
    attrs: {
      "type": "number",
      "clearable": "",
      "label": "手机号",
      "placeholder": "请输入手机号",
      "eventid": '1',
      "mpcomid": '1'
    },
    on: {
      "change": _vm.onMobileChange
    },
    model: {
      value: (_vm.mobile),
      callback: function($$v) {
        _vm.mobile = $$v
      },
      expression: "mobile"
    }
  }), _vm._v(" "), _c('van-field', {
    attrs: {
      "clearable": "",
      "label": "邮箱",
      "placeholder": "请输入邮箱地址",
      "eventid": '2',
      "mpcomid": '2'
    },
    on: {
      "change": _vm.onEmailChange
    },
    model: {
      value: (_vm.email),
      callback: function($$v) {
        _vm.email = $$v
      },
      expression: "email"
    }
  }), _vm._v(" "), _c('van-field', {
    attrs: {
      "clearable": "",
      "label": "地址",
      "placeholder": "请输入地址",
      "eventid": '3',
      "mpcomid": '3'
    },
    on: {
      "change": _vm.onAddressChange
    },
    model: {
      value: (_vm.address),
      callback: function($$v) {
        _vm.address = $$v
      },
      expression: "address"
    }
  })], 1), _vm._v(" "), _c('van-button', {
    attrs: {
      "type": "primary",
      "size": "large",
      "eventid": '4',
      "mpcomid": '5'
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
     require("vue-hot-reload-api").rerender("data-v-af62d944", esExports)
  }
}

/***/ })

},[198]);
//# sourceMappingURL=main.js.map