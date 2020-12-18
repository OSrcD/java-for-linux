require("../../../common/manifest.js");
require("../../../common/vendor.js");
global.webpackJsonp([3],{

/***/ 179:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
Object.defineProperty(__webpack_exports__, "__esModule", { value: true });
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_vue__ = __webpack_require__(4);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_vue___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_0_vue__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__index__ = __webpack_require__(180);



var app = new __WEBPACK_IMPORTED_MODULE_0_vue___default.a(__WEBPACK_IMPORTED_MODULE_1__index__["a" /* default */]);
app.$mount();

/***/ }),

/***/ 180:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__babel_loader_node_modules_mpvue_loader_lib_selector_type_script_index_0_index_vue__ = __webpack_require__(182);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__node_modules_mpvue_loader_lib_template_compiler_index_id_data_v_14f596a3_hasScoped_true_transformToRequire_video_src_source_src_img_src_image_xlink_href_node_modules_mpvue_loader_lib_selector_type_template_index_0_index_vue__ = __webpack_require__(187);
var disposed = false
function injectStyle (ssrContext) {
  if (disposed) return
  __webpack_require__(181)
}
var normalizeComponent = __webpack_require__(0)
/* script */

/* template */

/* styles */
var __vue_styles__ = injectStyle
/* scopeId */
var __vue_scopeId__ = "data-v-14f596a3"
/* moduleIdentifier (server only) */
var __vue_module_identifier__ = null
var Component = normalizeComponent(
  __WEBPACK_IMPORTED_MODULE_0__babel_loader_node_modules_mpvue_loader_lib_selector_type_script_index_0_index_vue__["a" /* default */],
  __WEBPACK_IMPORTED_MODULE_1__node_modules_mpvue_loader_lib_template_compiler_index_id_data_v_14f596a3_hasScoped_true_transformToRequire_video_src_source_src_img_src_image_xlink_href_node_modules_mpvue_loader_lib_selector_type_template_index_0_index_vue__["a" /* default */],
  __vue_styles__,
  __vue_scopeId__,
  __vue_module_identifier__
)
Component.options.__file = "src/pages/share/list/index.vue"
if (Component.esModule && Object.keys(Component.esModule).some(function (key) {return key !== "default" && key.substr(0, 2) !== "__"})) {console.error("named exports are not supported in *.vue files.")}
if (Component.options.functional) {console.error("[vue-loader] index.vue: functional components are not supported with templates, they should use render functions.")}

/* hot reload */
if (false) {(function () {
  var hotAPI = require("vue-hot-reload-api")
  hotAPI.install(require("vue"), false)
  if (!hotAPI.compatible) return
  module.hot.accept()
  if (!module.hot.data) {
    hotAPI.createRecord("data-v-14f596a3", Component.options)
  } else {
    hotAPI.reload("data-v-14f596a3", Component.options)
  }
  module.hot.dispose(function (data) {
    disposed = true
  })
})()}

/* harmony default export */ __webpack_exports__["a"] = (Component.exports);


/***/ }),

/***/ 181:
/***/ (function(module, exports) {

// removed by extract-text-webpack-plugin

/***/ }),

/***/ 182:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator__ = __webpack_require__(5);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_babel_runtime_helpers_asyncToGenerator__ = __webpack_require__(6);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1_babel_runtime_helpers_asyncToGenerator___default = __webpack_require__.n(__WEBPACK_IMPORTED_MODULE_1_babel_runtime_helpers_asyncToGenerator__);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_2__components_card_vue__ = __webpack_require__(183);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_3__utils_request__ = __webpack_require__(2);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_4__utils_api__ = __webpack_require__(1);


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
  components: {
    Card: __WEBPACK_IMPORTED_MODULE_2__components_card_vue__["a" /* default */]
  },
  data: function data() {
    return {
      notice: '',
      shares: '',
      more: true,
      pageNo: 1,
      searchWord: '',
      title: ''
    };
  },

  methods: {
    onChange: function onChange(event) {
      var _this = this;

      return __WEBPACK_IMPORTED_MODULE_1_babel_runtime_helpers_asyncToGenerator___default()( /*#__PURE__*/__WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator___default.a.mark(function _callee() {
        return __WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator___default.a.wrap(function _callee$(_context) {
          while (1) {
            switch (_context.prev = _context.next) {
              case 0:
                _this.title = event.mp.detail;
                _this.fetchSharePosts(true);

              case 2:
              case "end":
                return _context.stop();
            }
          }
        }, _callee, _this);
      }))();
    },
    findAllNotices: function findAllNotices() {
      var _this2 = this;

      return __WEBPACK_IMPORTED_MODULE_1_babel_runtime_helpers_asyncToGenerator___default()( /*#__PURE__*/__WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator___default.a.mark(function _callee2() {
        return __WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator___default.a.wrap(function _callee2$(_context2) {
          while (1) {
            switch (_context2.prev = _context2.next) {
              case 0:
                _context2.next = 2;
                return Object(__WEBPACK_IMPORTED_MODULE_3__utils_request__["a" /* request */])(__WEBPACK_IMPORTED_MODULE_4__utils_api__["d" /* NOTICE_URL */], 'GET', {});

              case 2:
                _this2.notice = _context2.sent;

              case 3:
              case "end":
                return _context2.stop();
            }
          }
        }, _callee2, _this2);
      }))();
    },
    fetchSharePosts: function fetchSharePosts(init) {
      var _this3 = this;

      return __WEBPACK_IMPORTED_MODULE_1_babel_runtime_helpers_asyncToGenerator___default()( /*#__PURE__*/__WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator___default.a.mark(function _callee3() {
        var title, sharesRemote;
        return __WEBPACK_IMPORTED_MODULE_0_babel_runtime_regenerator___default.a.wrap(function _callee3$(_context3) {
          while (1) {
            switch (_context3.prev = _context3.next) {
              case 0:
                if (init) {
                  _this3.pageNo = 1;
                  _this3.more = true;
                }
                wx.showNavigationBarLoading();
                title = _this3.title;
                _context3.next = 5;
                return Object(__WEBPACK_IMPORTED_MODULE_3__utils_request__["a" /* request */])(__WEBPACK_IMPORTED_MODULE_4__utils_api__["g" /* SHARE_POST_URL */] + '/q', 'GET', {
                  pageNo: _this3.pageNo,
                  title: title
                });

              case 5:
                sharesRemote = _context3.sent;

                if (sharesRemote.list.length < 10 && _this3.pageNo > 0) {
                  _this3.more = false;
                  console.log(_this3.more);
                }
                if (init) {
                  _this3.shares = sharesRemote.list;
                  wx.stopPullDownRefresh();
                } else {
                  // 下拉刷新，不能直接覆盖books 而是累加
                  _this3.shares = _this3.shares.concat(sharesRemote.list);
                }
                wx.hideNavigationBarLoading();

              case 9:
              case "end":
                return _context3.stop();
            }
          }
        }, _callee3, _this3);
      }))();
    },

    doCopyMe: function doCopyMe() {
      wx.setClipboardData({
        data: 'jumping_me',
        success: function success(res) {
          wx.getClipboardData({
            success: function success(res) {
              console.log(res);
            }
          });
        }
      });
    },
    doCopyGZH: function doCopyGZH() {
      wx.setClipboardData({
        data: 'itmuch_com',
        success: function success(res) {
          wx.getClipboardData({
            success: function success(res) {
              console.log(res);
            }
          });
        }
      });
    }
  },
  onReachBottom: function onReachBottom() {
    // 没有更多了
    if (!this.more) {
      return false;
    }
    this.pageNo = this.pageNo + 1;
    this.fetchSharePosts();
  },
  onPullDownRefresh: function onPullDownRefresh() {
    this.fetchSharePosts(true);
  },
  mounted: function mounted() {
    this.findAllNotices();
  },
  onShow: function onShow() {
    this.fetchSharePosts(true);
  }
});

/***/ }),

/***/ 183:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__babel_loader_node_modules_mpvue_loader_lib_selector_type_script_index_0_card_vue__ = __webpack_require__(185);
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_1__node_modules_mpvue_loader_lib_template_compiler_index_id_data_v_1cede892_hasScoped_true_transformToRequire_video_src_source_src_img_src_image_xlink_href_node_modules_mpvue_loader_lib_selector_type_template_index_0_card_vue__ = __webpack_require__(186);
var disposed = false
function injectStyle (ssrContext) {
  if (disposed) return
  __webpack_require__(184)
}
var normalizeComponent = __webpack_require__(0)
/* script */

/* template */

/* styles */
var __vue_styles__ = injectStyle
/* scopeId */
var __vue_scopeId__ = "data-v-1cede892"
/* moduleIdentifier (server only) */
var __vue_module_identifier__ = null
var Component = normalizeComponent(
  __WEBPACK_IMPORTED_MODULE_0__babel_loader_node_modules_mpvue_loader_lib_selector_type_script_index_0_card_vue__["a" /* default */],
  __WEBPACK_IMPORTED_MODULE_1__node_modules_mpvue_loader_lib_template_compiler_index_id_data_v_1cede892_hasScoped_true_transformToRequire_video_src_source_src_img_src_image_xlink_href_node_modules_mpvue_loader_lib_selector_type_template_index_0_card_vue__["a" /* default */],
  __vue_styles__,
  __vue_scopeId__,
  __vue_module_identifier__
)
Component.options.__file = "src/components/card.vue"
if (Component.esModule && Object.keys(Component.esModule).some(function (key) {return key !== "default" && key.substr(0, 2) !== "__"})) {console.error("named exports are not supported in *.vue files.")}
if (Component.options.functional) {console.error("[vue-loader] card.vue: functional components are not supported with templates, they should use render functions.")}

/* hot reload */
if (false) {(function () {
  var hotAPI = require("vue-hot-reload-api")
  hotAPI.install(require("vue"), false)
  if (!hotAPI.compatible) return
  module.hot.accept()
  if (!module.hot.data) {
    hotAPI.createRecord("data-v-1cede892", Component.options)
  } else {
    hotAPI.reload("data-v-1cede892", Component.options)
  }
  module.hot.dispose(function (data) {
    disposed = true
  })
})()}

/* harmony default export */ __webpack_exports__["a"] = (Component.exports);


/***/ }),

/***/ 184:
/***/ (function(module, exports) {

// removed by extract-text-webpack-plugin

/***/ }),

/***/ 185:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
/* harmony import */ var __WEBPACK_IMPORTED_MODULE_0__utils_api__ = __webpack_require__(1);
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
  props: ['share'],
  computed: {
    detailUrl: function detailUrl() {
      var id = this.share.id;
      var downloadUrl = this.share.downloadUrl;
      // 如果没有下载地址，说明没兑换，跳转到兑换页
      if (!downloadUrl) {
        return '/pages/share/detail/main?id=' + id;
      } else {
        return '/pages/share/buy-success/main?id=' + id;
      }
    },
    cover: function cover() {
      return __WEBPACK_IMPORTED_MODULE_0__utils_api__["a" /* BASE_API_URL */] + '/' + this.share.cover;
    },
    summary: function summary() {
      var summary = this.share.summary;
      if (summary && summary.length > 30) {
        summary = summary.substring(0, 30) + '...';
      }
      return summary;
    }
  },
  methods: {
    preview: function preview() {
      console.log('cover', this.cover);
      wx.previewImage({
        current: this.cover,
        urls: [this.cover]
      });
    }
  }
});

/***/ }),

/***/ 186:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
var render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;
  return _c('a', {
    attrs: {
      "href": _vm.detailUrl
    }
  }, [_c('div', {
    staticClass: "itmuch-card"
  }, [_c('div', {
    staticClass: "thumb",
    attrs: {
      "eventid": '0'
    },
    on: {
      "click": function($event) {
        $event.stopPropagation();
        _vm.preview($event)
      }
    }
  }, [_c('img', {
    staticClass: "img",
    attrs: {
      "src": _vm.cover,
      "mode": "aspectFit"
    }
  }), _vm._v(" "), (_vm.share.isOriginal) ? _c('div', {
    staticClass: "tag origin"
  }, [_vm._v("\n        原创\n      ")]) : _c('div', {
    staticClass: "tag reprint"
  }, [_vm._v("\n        转载\n      ")])]), _vm._v(" "), _c('div', {
    staticClass: "detail"
  }, [_c('div', {
    staticClass: "mid"
  }, [_c('div', {
    staticClass: "title"
  }, [_vm._v("\n          " + _vm._s(_vm.share.title) + "\n        ")]), _vm._v(" "), _c('div', {
    staticClass: "summary"
  }, [_vm._v(_vm._s(_vm.summary))])]), _vm._v(" "), _c('div', {
    staticClass: "right"
  }, [_c('div', [_vm._v(_vm._s(_vm.share.price) + "积分")]), _vm._v(" "), (_vm.share.downloadUrl) ? _c('div', {
    staticClass: "right"
  }, [_vm._v("下载")]) : _c('div', {
    staticClass: "right"
  }, [_vm._v("兑换")])])])])])
}
var staticRenderFns = []
render._withStripped = true
var esExports = { render: render, staticRenderFns: staticRenderFns }
/* harmony default export */ __webpack_exports__["a"] = (esExports);
if (false) {
  module.hot.accept()
  if (module.hot.data) {
     require("vue-hot-reload-api").rerender("data-v-1cede892", esExports)
  }
}

/***/ }),

/***/ 187:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
var render = function () {var _vm=this;var _h=_vm.$createElement;var _c=_vm._self._c||_h;
  return _c('div', [_c('official-account', {
    attrs: {
      "mpcomid": '0'
    }
  }), _vm._v(" "), _c('van-tabs', {
    attrs: {
      "eventid": '3',
      "mpcomid": '8'
    },
    model: {
      value: (_vm.active),
      callback: function($$v) {
        _vm.active = $$v
      },
      expression: "active"
    }
  }, [_c('van-tab', {
    attrs: {
      "title": "发现",
      "mpcomid": '4'
    }
  }, [_c('van-notice-bar', {
    attrs: {
      "text": _vm.notice.content,
      "mpcomid": '1'
    }
  }), _vm._v(" "), _c('van-search', {
    attrs: {
      "placeholder": "请输入关键词",
      "eventid": '0',
      "mpcomid": '2'
    },
    on: {
      "change": _vm.onChange
    }
  }), _vm._v(" "), _c('ul', _vm._l((_vm.shares), function(share, index) {
    return _c('li', {
      key: index
    }, [_c('Card', {
      key: index,
      attrs: {
        "share": share,
        "mpcomid": '3-' + index
      }
    })], 1)
  }))], 1), _vm._v(" "), _c('van-tab', {
    attrs: {
      "title": "使用说明",
      "mpcomid": '7'
    }
  }, [_c('div', {
    staticClass: "shuoming"
  }, [_c('p', [_vm._v("资源均为免费，兑换后即可查看下载地址；点击"), _c('span', [_vm._v("我的 -> 我的兑换")]), _vm._v("，即可查看、下载兑换过的资源。")]), _vm._v(" "), _c('h3', [_vm._v("积分获得方式")]), _vm._v(" "), _c('ul', [_c('li', [_vm._v(" > 每日签到")]), _vm._v(" "), _c('li', [_vm._v(" > 投稿")]), _vm._v(" "), _c('li', [_vm._v(" > 转发")]), _vm._v(" "), _c('li', [_vm._v(" > 提建议、意见（尚未完成）")])], 1), _vm._v(" "), _c('h3', [_vm._v("深入交流")]), _vm._v(" "), _c('ul', [_c('li', [_vm._v(" > 技术交流群QQ群：731548893")]), _vm._v(" "), _c('li', [_vm._v(" > 技术交流微信群：加我微信，注明加微信群")]), _vm._v(" "), _c('li', [_vm._v(" > 私人微信：jumping_me\n            "), _c('van-button', {
    attrs: {
      "type": "primary",
      "size": "mini",
      "eventid": '1',
      "mpcomid": '5'
    },
    on: {
      "click": _vm.doCopyMe
    }
  }, [_vm._v("复制")])], 1)], 1), _vm._v(" "), _c('h3', [_vm._v("公众号(技术干货分享)")]), _vm._v(" "), _c('div', [_vm._v("\n          由于小程序不支持二维码识别，亲们可使用如下方式关注我的公众号：\n        ")]), _vm._v(" "), _c('ul', [_c('li', [_vm._v(" > 点击"), _c('span', [_vm._v("右上角 -> 关于IT牧场 -> 相关公众号")]), _vm._v("即可关注，操作简单，只需5秒！")]), _vm._v(" "), _c('li', [_vm._v(" > 公众号微信：itmuch_com\n            "), _c('van-button', {
    attrs: {
      "type": "danger",
      "size": "mini",
      "eventid": '2',
      "mpcomid": '6'
    },
    on: {
      "click": _vm.doCopyGZH
    }
  }, [_vm._v("复制")])], 1)], 1)], 1)])], 1)], 1)
}
var staticRenderFns = []
render._withStripped = true
var esExports = { render: render, staticRenderFns: staticRenderFns }
/* harmony default export */ __webpack_exports__["a"] = (esExports);
if (false) {
  module.hot.accept()
  if (module.hot.data) {
     require("vue-hot-reload-api").rerender("data-v-14f596a3", esExports)
  }
}

/***/ })

},[179]);
//# sourceMappingURL=main.js.map