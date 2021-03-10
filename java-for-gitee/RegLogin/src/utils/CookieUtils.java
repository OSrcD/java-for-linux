package utils;

import javax.servlet.http.Cookie;

public class CookieUtils {
	public static Cookie findCookie(Cookie[] cookies,String name) {
		if(cookies == null) {
			return null;
		}else {
			for(Cookie cookie : cookies) {
				if(name.equals(cookie.getName())) {
					return cookie;
				}
			}
			return null;
		}
	}
}
