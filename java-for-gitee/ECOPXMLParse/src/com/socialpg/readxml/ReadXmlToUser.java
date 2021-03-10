package com.opendevel.readxml;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.xml.sax.Attributes;
import org.xml.sax.InputSource;
import org.xml.sax.Locator;
import org.xml.sax.SAXException;
import org.xml.sax.SAXParseException;
import org.xml.sax.helpers.DefaultHandler;

import com.opendevel.entity.UserInterface;
import com.opendevel.entity.UserXmlqy;
import com.opendevel.entity.UserXmlrz;

public class ReadXmlToUser extends DefaultHandler {

	

	private String currentTag;

	
	
	private static Map<String,String> ContentMap;
	 
	@Override
	public void startDocument() throws SAXException {
	
		
		ContentMap = new HashMap<String,String>();
	}

	@Override
	public void endDocument() throws SAXException {
		System.out.println("�����ĵ�����");
		
		
		
	
	}
	
	
	
	public static UserInterface  getUser(String name,UserInterface userInterface) {
		
		if ("UserXmlrz".equals(name)) {
			
			 userInterface = new UserXmlrz(ContentMap.get("PointTx"), 
					ContentMap.get("site_id"), ContentMap.get("CompanyID"), 
					ContentMap.get("DeptID"), ContentMap.get("StoreID"), 
					ContentMap.get("TxType"), ContentMap.get("DeptID"), ContentMap.get("Status"),
					ContentMap.get("ErrorMsg"), ContentMap.get("Param1"), 
					ContentMap.get("Param2"), ContentMap.get("Param3"), ContentMap.get("Param4"), 
					ContentMap.get("Param5"));
			 
		}else if("UserXmlqy".equals(name)) {
			userInterface = new UserXmlqy(ContentMap.get("PointTx"), ContentMap.get("site_id"),
					ContentMap.get("CompanyID"), ContentMap.get("DeptID"),
					ContentMap.get("StoreID"), ContentMap.get("TermID"),
					ContentMap.get("TxID"), ContentMap.get("TxType"), ContentMap.get("BusinessDate"),
					ContentMap.get("Time"), ContentMap.get("ONLStatus"), ContentMap.get("Date"),
					ContentMap.get("AwardType"), ContentMap.get("PointCalc"),
					ContentMap.get("MasterChk"), ContentMap.get("PointTargetAmount"),
					ContentMap.get("PointExcludeAmount"), ContentMap.get("AwardPoint"),
					ContentMap.get("RewardPoint"), ContentMap.get("PointID"),
					ContentMap.get("CanTermID"), ContentMap.get("CanTxID"), 
					ContentMap.get("CanBusinessDate"), ContentMap.get("CanTime"));
		}
		
		return userInterface;
	
		
		
	}

	@Override
	public void startElement(String uri, String localName, String qName, Attributes attributes) throws SAXException {
	
		currentTag=qName;
		if(attributes.getLength()>0) {
			System.out.println("<"+currentTag+">Ԫ�ص���������:");
			
			for(int i=0;i<attributes.getLength();i++) {
				System.out.println(attributes.getQName(i)+"--->"+attributes.getValue(i));
				ContentMap.put(attributes.getQName(i), attributes.getValue(i));
			}
		}
	}

	@Override
	public void endElement(String uri, String localName, String qName) throws SAXException {
	
		
		
		
	}
	


	@Override
	public void characters(char[] ch, int start, int length) throws SAXException {

		super.characters(ch, start, length);
		String content = new String(ch,start,length);
		if(content.trim().length()>0) {
			System.out.println("<"+currentTag+">Ԫ�ص�ֵ��:"+content.trim());
			ContentMap.put(currentTag, content.trim());
			System.out.println(ContentMap.get("CompanyID"));
		}
		
	}
	
	
	
	
	
}
