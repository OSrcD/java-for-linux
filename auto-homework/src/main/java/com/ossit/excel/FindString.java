package com.ossit.excel;

import org.apache.poi.xssf.usermodel.XSSFSheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

import java.io.FileInputStream;
import java.io.IOException;

public class FindString {

    public static StringBuilder findString(String fileName,String findContent){

        try {
            XSSFWorkbook xssfWorkbook = new XSSFWorkbook(new FileInputStream(fileName));

            XSSFSheet xssfSheet = xssfWorkbook.getSheetAt(0);

            int maxRow = xssfSheet.getLastRowNum();

            for(int row=0;row <= maxRow;row++){
                short lastCellNum = xssfSheet.getRow(row).getLastCellNum();

                for(int cellNum = 0;cellNum < lastCellNum;cellNum++){

                    boolean flag = xssfSheet.getRow(row).getCell(cellNum).toString().contains(findContent);
                    if(flag){
                       StringBuilder sb = new StringBuilder(xssfSheet.getRow(row).getCell(cellNum+1).toString());
//                       String [] str = xssfSheet.getRow(row).getCell(cellNum).toString().split("\n");
                       return sb;
//                        for(String st : str){
//
//                            if(!st.equals("")) {
//                                System.out.println(st);
//                                System.out.println("--------------------");
//                            }
//                        }
                    }

                }


            }


        }catch (IOException e){
            e.printStackTrace();

        }

        return null;
    }
}
