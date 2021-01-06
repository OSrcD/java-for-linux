import {app, BrowserWindow, ipcMain, Menu} from 'electron';

if (process.env.NODE_ENV !== 'development') {
    global.__static = require('path').join(__dirname, '/static').replace(/\\/g, '\\\\')
}

let mainWindow
const winURL = process.env.NODE_ENV === 'development'
    ? `http://localhost:9080`
    : `file://${__dirname}/index.html`




/**
 * 开启一个子窗口
 */
function subWindow() {
    var subWindow = new BrowserWindow({
        height: 568, // 窗口高度
        useContentSize: true,
        width: 905, // 窗口宽度
        center: true, // 窗口居中
        webPreferences: {
            nodeIntegration: true, // 集成node框架
            enableRemoteModule: true
        },
    })

    // 加载路由
    subWindow.loadURL(winURL);

    // 监听关闭事件
    subWindow.on('closed', () => {
        subWindow = null;
    });

    // 关闭子窗口开发者工具
    subWindow.webContents.closeDevTools()
}


const template = [
    {
        label: 'File',
        submenu: [
        ]
    },
    {
        label: 'Edit',
        submenu: [
            {role: 'undo'},
            {role: 'redo'},
            {type: 'separator'},
            {role: 'cut'},
            {role: 'copy'},
            {role: 'paste'},
            {role: 'pasteandmatchstyle'},
            {role: 'delete'},
            {role: 'selectall'}
        ]
    },
    {
        label: 'View',
        submenu: [
            {role: 'reload'},
            {role: 'forcereload'},
            {role: 'toggledevtools'},
            {type: 'separator'},
            {role: 'resetzoom'},
            {role: 'zoomin'},
            {role: 'zoomout'},
            {type: 'separator'},
            {role: 'togglefullscreen'}
        ]
    },
    {
        role: 'window',
        submenu: [
            {role: 'minimize'},
            {role: 'close'}
        ]
    },
    {
        role: 'help',
        submenu: [
            {
                label: 'Learn More',
                click () { require('electron').shell.openExternal('https://electron.atom.io'); }
            }
        ]
    }
];

if (process.platform === 'darwin') {
    template.unshift({
        label: app.getName(),
        submenu: [
            {role: 'about'},
            {type: 'separator'},
            {role: 'services', submenu: []},
            {type: 'separator'},
            {role: 'hide'},
            {role: 'hideothers'},
            {role: 'unhide'},
            {type: 'separator'},
            {role: 'quit'}
        ]
    });

    // Edit menu
    template[2].submenu.push(
        {type: 'separator'},
        {
            label: 'Speech',
            submenu: [
                {role: 'startspeaking'},
                {role: 'stopspeaking'}
            ]
        }
    );

    // Window menu
    template[4].submenu = [
        {
            label: 'New Window',
            click: function () {
                subWindow();
            }
        },
        {role: 'close'},
        {role: 'minimize'},
        {role: 'zoom'},
        {type: 'separator'},
        {role: 'front'},

    ];


}

const menu = Menu.buildFromTemplate(template);
Menu.setApplicationMenu(menu);


app.on('ready', function () {
});








/**
 * 实例化一个主窗口
 */
function createWindow() {
    mainWindow = new BrowserWindow({
        height: 568, // 窗口高度
        useContentSize: true,
        width: 905, // 窗口宽度
        center: true, // 窗口居中
        webPreferences: {
            nodeIntegration: true, // 集成node框架
            enableRemoteModule: true
        },


    })

    /**
     * 加载自定义菜单
     * @type {Electron.Menu}
     */
    // const mainMenu = Menu.buildFromTemplate(Menus);
    // Menu.setApplicationMenu(mainMenu);





    /**
     * 主进程监听打开窗口事件
     */
    ipcMain.on('openSubWindow', e => {

    });

    // 窗口居中


    // 关闭开发者工具
    mainWindow.webContents.closeDevTools()


    // 调用appProperties函数
    appProperties();

    // 加载index.html文件
    mainWindow.loadURL(winURL)

    /**
     * 监听关闭窗口
     */
    mainWindow.on('closed', () => {
        mainWindow = null
    })

}

/**
 * 监听 ready 事件 创建主窗口
 */
app.on('ready', createWindow)


/**
 * 监听所有窗口都关闭，程序退出
 */
app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
        app.quit()
    }
})

/**
 * 监听 activate 如果主窗口为空 创建主窗口对象
 */
app.on('activate', () => {
    if (mainWindow === null) {

        createWindow();

    }
})

/**
 * 开启渲染进程调用本地API
 */
function appProperties() {
    app.allowRendererProcessReuse = false;
}


