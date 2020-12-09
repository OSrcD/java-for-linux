import { app, BrowserWindow} from 'electron'

if (process.env.NODE_ENV !== 'development') {
  global.__static = require('path').join(__dirname, '/static').replace(/\\/g, '\\\\')
}

let mainWindow
const winURL = process.env.NODE_ENV === 'development'
  ? `http://localhost:9080`
  : `file://${__dirname}/index.html`

/**
 * 实例化一个窗口
 */
function createWindow () {
  mainWindow = new BrowserWindow({
    height: 568, // 窗口高度
    useContentSize: true,
    width: 905, // 窗口宽度
    center: true, // 窗口居中
    webPreferences:{
      nodeIntegration: true, // 集成node框架
      enableRemoteModule: true 
    },
    
    
 
  })

  // 窗口居中

 
  // 关闭开发者工具
  mainWindow.webContents.closeDevTools() 
 

  // 调用appProperties函数
  appProperties();

  // 加载index.html文件
  mainWindow.loadURL(winURL)
  
  mainWindow.on('closed', () => {
    mainWindow = null
  })

}

  
app.on('ready', createWindow)

app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit()
  }
})

app.on('activate', () => {
  if (mainWindow === null) {
    
    createWindow();
    
  }
})

/**
 * 开启渲染进程调用本地API
 */
function appProperties (){
  app.allowRendererProcessReuse = false;
}

