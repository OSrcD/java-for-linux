package com.opendevel.createxml;

import java.lang.reflect.Field;

import javax.xml.transform.sax.TransformerHandler;

import org.xml.sax.SAXException;
import org.xml.sax.helpers.AttributesImpl;

import com.opendevel.createxml.util.CreateXMlUtil;
import com.opendevel.entity.UserInterface;
import com.opendevel.entity.UserXmlqy;
import com.opendevel.entity.UserXmlrz;

public class CreateUserXmlqyFile {

	public void generateXMlFile(String generateXMlFileName,UserInterface userXmlqy) {
		
		TransformerHandler transformerHandler =  CreateXMlUtil.getTFHandler(generateXMlFileName);

		try {
			transformerHandler.startDocument();
			AttributesImpl attributesImpl = new AttributesImpl();
			transformerHandler.startDocument();
			Class cls = userXmlqy.getClass();
			
			Field [] fields = cls.getDeclaredFields();
			String value;
			transformerHandler.startElement("", "", "user",attributesImpl);
			for(Field field:fields) {
				field.setAccessible(true);
				transformerHandler.startElement("", "", field.getName(), attributesImpl);
			
				try {
					if(	(value=(String)field.get(userXmlqy))!=null) {
						transformerHandler.characters(value.toCharArray(), 0, value.length());
					}
					
					transformerHandler.endElement("","", field.getName());
					
				} catch (IllegalArgumentException e) {
					e.printStackTrace();
				} catch (IllegalAccessException e) {
					e.printStackTrace();
				}
			}
			
		transformerHandler.endElement("", "", "user");
		transformerHandler.endDocument();
		System.out.println("userXmlqy XML�ĵ��������");
		} catch (SAXException e) {
			e.printStackTrace();
		}
		
		
		
	}
	
	
}
