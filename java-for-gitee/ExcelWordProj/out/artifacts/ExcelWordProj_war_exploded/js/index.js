/**
 * 方法描述:单击二级菜单（页面左部菜单），初始化主页面
 */
function clickSecondMenu(element,src) {
	var nodes = document.getElementById('menuDiv').children;
	for(var i = 0; i < nodes.length; i++) {
		nodes[i].children[0].className = '';
	}
	
	element.children[0].className = 'on';
	
	document.getElementById('mainPage').setAttribute('src',src);
}