<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<meta http-equiv="X-UA-Compatible" content="IE=9; IE=8; IE=7; IE=EDGE" />
		<title>JavaWeb实现导入导出</title>
		<link href="css/all.css" rel="stylesheet" type="text/css" />
		<link href="css/pop.css" rel="stylesheet" type="text/css" />
		<link href="css/index.css" rel="stylesheet" type="text/css" />
		<script src="js/index.js" type="text/javascript"></script>
	</head>
	<body>
		<!-- 蒙版DIV -->
		<div id="mengban" style="display: none"></div>
		<form method="post">
			<div id="header">
				<div class="iheader">
					<div class="logo">
						<a href="#"><img src="" alt="" height="88px" width="99px" /></a>
					</div>
					<div style="height: 44px;"></div>
					<ul class="nav" id="mainMenuUl">
						<li class="on"><a><span>导入/导出</span></a></li>
					</ul>
				</div>
			</div>
			<div id="container">
				<table style="vertical-align: top" cellspacing="0" cellpadding="0"
					bgcolor="#e1e9eb" border="0">
					<tbody>
						<tr>
							<td class="leftTd" style="vertical-align: top" width="150">
								<div class="left">
									<div class="ileft" id="menuDiv">
										<h3 onclick="clickSecondMenu(this,'${basePath}/importExcelInit')">
											<a>导入Excel</a>
										</h3>
										<h3 onclick="clickSecondMenu(this,'${basePath}/exportExcelInit')">
											<a>导出Excel</a>
										</h3>
										<h3 onclick="clickSecondMenu(this,'${basePath}/importWordInit')">
											<a>导入Word</a>
										</h3>
										<h3 onclick="clickSecondMenu(this,'${basePath}/exportWordInit')">
											<a>导出Word</a>
										</h3>
									</div>
								</div>
							</td>
							<td width="7">
								<div class="pointer"></div>
							</td>
							<td style="vertical-align: top" height="600px" width="100%">
								<br/><iframe id="mainPage" src="" frameborder="0" height="580px" width="100%"></iframe><br />
							</td>
						</tr>
					</tbody>
				</table>
			</div>
			<div id="footer">
				<div class="copyright">慕课网</div>
				<div class="flr">copyright &copy;</div>
			</div>
		</form>
	</body>
</html>