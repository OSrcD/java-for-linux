package com.opendevel.xmlparse;

import java.io.IOException;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.xml.sax.SAXException;

import com.opendevel.createxml.CreateUserXmlqyFile;
import com.opendevel.entity.UserInterface;
import com.opendevel.entity.UserXmlqy;
import com.opendevel.entity.UserXmlrz;
import com.opendevel.readxml.ReadXmlToUser;


public class UserParse {

	public static void main(String[] args) {
	SAXParserFactory factory  =  SAXParserFactory.newInstance();

	UserInterface userXmlrz = new UserXmlrz();
	UserInterface userXmlqy = new UserXmlqy();
		try {
			SAXParser parse = factory.newSAXParser();
			parse.parse("ECOPrz.xml", new ReadXmlToUser());
			userXmlrz =ReadXmlToUser.getUser("UserXmlrz", userXmlrz);
			
			System.out.println(userXmlrz);
			
			parse.parse("ECOPqy.xml", new ReadXmlToUser());
			userXmlqy =ReadXmlToUser.getUser("UserXmlqy", userXmlqy);
			System.out.println(userXmlqy);
			
		} catch (ParserConfigurationException e) {
			e.printStackTrace();
		} catch (SAXException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		 CreateUserXmlqyFile createUserXmlqyFile = new CreateUserXmlqyFile();
		 createUserXmlqyFile.generateXMlFile("userXmlqy.xml", userXmlqy);
		
	}

}
