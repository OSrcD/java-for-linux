package com.opendevel.runapp;

import java.awt.Desktop;
import java.io.File;
import java.io.IOException;

public class RunStudy {

	public static void main(String[] args) {
		
		String qianzui = "D:\\my_software_engineering\\my_java_project\\ProjDoc\\";
		
		String [] command = {qianzui+"Junior Engineer of Java - Cui Maozhi.docx","D:\\my_software_engineering\\my_vs_code\\Code.exe",qianzui+"my_css_note.docx",
			"D:\\my_windows_programfiles\\my_java_video\\慕课网从网页搭建入门Java Web\\步骤一：网页搭建入门\\1.HTML入门\\第4章 带格式化标签，表格及表单",
			"D:\\my_windows_programfiles\\my_qq\\Bin\\QQ.exe"
				
		};
		
		
		for(String myOpenFile:command) {
			try {
				Desktop.getDesktop().open(new File(myOpenFile));
				
			} catch (IOException e) {
				e.printStackTrace();
				
			}
		}
		
		
		
		while(true) {
			System.exit(1);
		}
	
		
		
	}

}
