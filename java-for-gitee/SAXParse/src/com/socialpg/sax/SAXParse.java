package com.opendevel.sax;

import java.io.IOException;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.xml.sax.SAXException;

import com.opendevel.sax.handler.MukeHandler;

public class SAXParse {

	public static void main(String[] args) throws ParserConfigurationException, SAXException, IOException {
		SAXParserFactory factory  =  SAXParserFactory.newInstance();
		
		SAXParser parse = factory.newSAXParser();
		parse.parse("dtd.xml", new MukeHandler());
	}

}
