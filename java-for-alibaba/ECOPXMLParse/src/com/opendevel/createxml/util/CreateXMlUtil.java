package com.opendevel.createxml.util;

import javax.xml.transform.OutputKeys;
import javax.xml.transform.Result;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.sax.SAXTransformerFactory;
import javax.xml.transform.sax.TransformerHandler;
import javax.xml.transform.stream.StreamResult;



public class CreateXMlUtil {
	
	public static TransformerHandler getTFHandler(String XMLFileName) {
		TransformerHandler transformerHandler = null;
		Result  result = new StreamResult(XMLFileName);
		
		SAXTransformerFactory saxTransformerFactory = (SAXTransformerFactory)SAXTransformerFactory.newInstance();
		
		try {
			 transformerHandler  = saxTransformerFactory.newTransformerHandler();
			transformerHandler.setResult(result);
			Transformer transformer = transformerHandler.getTransformer();
			transformer.setOutputProperty(OutputKeys.INDENT, "yes");
		
		} catch (TransformerConfigurationException e) {
			e.printStackTrace();
		}
		return transformerHandler;
		
		
	
		
	}

}
