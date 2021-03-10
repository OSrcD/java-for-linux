<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<meta http-equiv="X-UA-Compatible" content="IE=9; IE=8; IE=7; IE=EDGE" />
	<title></title>
	<link rel="stylesheet" type="text/css" href="css/all.css" />
	<link rel="stylesheet" type="text/css" href="css/pop.css" />
	<link rel="stylesheet" type="text/css" href="css/main.css" />
	</head>
	<body style="background: #e1e9eb;">
		<form id="mainForm" method="post" action="${basePath}/exportWord1">
            <input type="hidden" name="isDocx" id="isDocx"/>
			<div class="right">
				<div class="current">
					当前位置：<a href="###">导入/导出</a> &gt; 导出Word
				</div>
				<div class="rightCont">
					<p class="g_title fix">导出Word</p>
					<table class="tab1" width="100%">
						<tbody>
							<tr>
								<td align="right" width="10%">姓名<font color="red">*</font>：
								</td>
								<td width="30%"><input name="name" value="张三"
									class="allInput" style="width: 100%;" type="text" /></td>
								<td align="right" width="10%">年龄<font color="red">*</font>：
								</td>
								<td width="30%"><input name="age" value="40"
									class="allInput" style="width: 100%;" type="text" /></td>
							</tr>
							<tr>
								<td align="right" width="10%">时间<font color="red">*</font>：
								</td>
								<td width="30%"><input name="time" value="2016-01-01"
									class="allInput" style="width: 100%;" type="text" /></td>
								<td align="right" width="10%"></td>
								<td width="30%"></td>
							</tr>
						</tbody>
					</table>
					<div style="text-align: center; margin-top: 30px;">
						<input class="tabSub" value="导出03" type="button" onclick="document.getElementById('isDocx').value = '';document.getElementById('mainForm').submit();"/>&nbsp;&nbsp;&nbsp;&nbsp;
						<input class="tabSub" value="导出07" type="button" onclick="document.getElementById('isDocx').value = '1';document.getElementById('mainForm').submit();"/>
					</div>
				</div>
			</div>
		</form>
	</body>
</html>