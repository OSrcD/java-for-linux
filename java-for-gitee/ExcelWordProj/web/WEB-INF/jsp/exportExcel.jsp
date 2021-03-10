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
		<form action="${basePath}/exportExcel" id="mainForm" method="post">
			<div class="right">
				<div class="current">
					当前位置：<a href="#">导入/导出</a> &gt; 导出Excel
				</div>
				<div class="rightCont">
					<p class="g_title fix">导出Excel</p>
					<table class="tab1">
						<tbody>
							<tr>
								<td align="right" width="80">标题：</td>
								<td width="280">
                                    <input id="title" value="" style="width: 100%;" class="allInput" type="text" />
                                </td>
								<td style="text-align: right;" width="150"><input
									class="tabSub" value="查询" onclick="" type="button" />&nbsp;&nbsp;&nbsp;&nbsp;
									<input class="tabSub" value="导出" onclick="document.getElementById('mainForm').submit();" type="button" /></td>
							</tr>
						</tbody>
					</table>
					<div class="zixun fix">
						<table class="tab2" width="100%">
							<tbody>
								<tr>
									<th>序号</th>
									<th>姓名</th>
									<th>年龄</th>
									<th>出生日期</th>
								</tr>
								<tr>
									<td>1</td>
									<td>路人甲</td>
									<td>18</td>
									<td>2010-01-01</td>
								</tr>
								<tr>
									<td>2</td>
									<td>路人乙</td>
									<td>19</td>
									<td>2010-01-02</td>
								</tr>
								<tr>
									<td>3</td>
									<td>路人丙</td>
									<td>20</td>
									<td>2010-01-03</td>
								</tr>
							</tbody>
						</table>
					</div>
				</div>
			</div>
		</form>
	</body>
</html>