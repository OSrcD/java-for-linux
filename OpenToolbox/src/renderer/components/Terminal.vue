<template>
    <div id="xterm" @keydown.ctrl.alt.50="DefaultWindowColor()" @keydown.ctrl.alt.51="ChangeWindowColor()" :style="{backgroundImage: 'url(' + background + ')'} " >
    </div>
</template>

<style scoped>
#xterm {
  margin-left: 8.6px;
  height: 100%;
  width: 100%;
  background: no-repeat center;
  background-size: contain;
}

</style>

<script>

const os = require('os');
const pty = require('node-pty');
const {remote, ipcRenderer} = require('electron');
import {Terminal} from 'xterm';
import {FitAddon} from 'xterm-addon-fit';
import background from '@/assets/background.png'


export default {
  name: 'Terminal',

  data() {
    return {
      xterm: null,
      ptyProcess: null,
      shell: null,
      fitAddon: null,
      background: background
    }
  },

  methods: {

    /**
     * 初始化Terminal终端
     */
    initializeTerminal: function () {


      const that = this;

      /**
       * 初始化xterm
       */
      this.xterm = new Terminal({

        cursorBlink: true, // 光标闪烁
        fontSize: 26, // 字体大小
        theme: {

          foreground: 'lightgray', // 前景色
          background: "#0000", // 背景色


        },
        allowTransparency: true // 开启透明

      });

      /**
       * 使用自适应宽度、高度插件并把终端挂载在名为xterm元素上
       */
      this.fitAddon = new FitAddon();
      this.xterm.loadAddon(this.fitAddon);
      this.xterm.open(document.getElementById('xterm'));
      this.fitAddon.fit();

      /**
       * 初始化node-pty
       */
      this.shell = process.env[os.platform() === 'win32' ? 'COMSPEC' : 'SHELL'];
      this.ptyProcess = pty.spawn(this.shell, [], {
        rows: that.xterm.rows || 80,
        cols: that.xterm.cols || 24,
        cwd: process.env.HOME,
        env: process.env,
        encoding: 'utf8'
      });

      // 写命令
      this.ptyProcess.write('source ~/.bash_profile\r');


      this.ptyProcess.write('clear\r');

      /**
       * xterm监听键盘数据
       */
      this.xterm.onData(send => {
        this.ptyProcess.write(send);

      });

      /**
       * node-pty监听xterm发送过来数据
       */
      this.ptyProcess.onData(recv => {

        /**
         * 回显数据给xterm
         */
        this.xterm.write(recv);
      });


      /**
       * 监听窗口大小发生改变，重新调用插件，以适应父容器的宽和高
       */
      window.addEventListener("resize", resizeScreen);


      function resizeScreen() {
        that.fitAddon.fit();
      }

      /**
       * xterm大小发生改变，node-pty的大小要同步改变
       */
      this.xterm.onResize((size) => {
        that.ptyProcess.resize(size.cols, size.rows);
      })

    },

    /**
     * 改变颜色
     */
    ChangeWindowColor: function () {
      this.xterm.setOption('theme',{
        foreground: 'lightgray', // 前景色
        background: "#0004", // 背景色
      });
    },

    /**
     * 还原默认颜色
     */
    DefaultWindowColor: function () {
      this.xterm.setOption('theme',{
        foreground: 'lightgray', // 前景色
        background: "#0000", // 背景色
      });
    },

  },


  mounted() {
    // 调用初始化函数
    this.initializeTerminal();
    // 重新设置大小
    remote.getCurrentWindow().setSize(1156, 746);
  },


}


</script>