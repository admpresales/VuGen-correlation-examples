Action()
{

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_url("success.txt", 
		"URL=http://detectportal.firefox.com/success.txt", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t11.inf", 
		LAST);

	web_url("success.txt_2", 
		"URL=http://detectportal.firefox.com/success.txt", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t12.inf", 
		LAST);

	web_url("success.txt_3", 
		"URL=http://detectportal.firefox.com/success.txt", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t13.inf", 
		LAST);

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("LoadRunner_Correlation_Challenge_Exp.aspx", 
		"URL=http://loadrunnertips.com/LoadRunner_Correlation_Challenge_Exp.aspx", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=http://detectportal.firefox.com/success.txt", "Referer=", ENDITEM, 
		"Url=/img/images.jpg", ENDITEM, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	web_submit_form("LoadRunner_Correlation_Challenge_Exp.aspx_2", 
		"Snapshot=t15.inf", 
		ITEMDATA, 
		"Name=ctl00$head$btnStart", "Value=Start", ENDITEM, 
		LAST);

	web_submit_form("LoadRunner_Correlation_Challenge_Exp.aspx_3", 
		"Snapshot=t16.inf", 
		ITEMDATA, 
		"Name=ctl00$head$QNo1.8", "Value=Alwar", ENDITEM, 
		"Name=ctl00$head$btnNext", "Value=Next", ENDITEM, 
		EXTRARES, 
		"Url=/WebResource.axd?d=Dni4Dwp2sE7BkxnwJrEAA5649Tlmnpvwn2La2DRwkPVt5D7zaVMO-EzSoZ_dVp6PBIJvfHbzOMQZeZkiuwwsKjfi5gBPV8iFZodpTRMsMug1&t=636765212300000000", ENDITEM, 
		"Url=/WebResource.axd?d=_ik9MG88W60F3HCI3_iYhWbegkhYG7ydNd13f4OiDs4o4SXDkA3axp76aGF6nX2u8QN6h5kURIRHRFRTQRGwTHWg_sLQ5n4rRo3B6oaZXaI1&t=636765212300000000", ENDITEM, 
		LAST);

	web_submit_data("LoadRunner_Correlation_Challenge_Exp.aspx_4", 
		"Action=http://loadrunnertips.com/LoadRunner_Correlation_Challenge_Exp.aspx", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://loadrunnertips.com/LoadRunner_Correlation_Challenge_Exp.aspx", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=__EVENTTARGET", "Value=", ENDITEM, 
		"Name=__EVENTARGUMENT", "Value=", ENDITEM, 
		"Name=__VIEWSTATE", "Value=/wEPDwUKLTMwNzk0OTUxN2RkiNLWKXvunUPD8hG0KuCM1zvFDlEueuKlFq9Ah2nRCFs=", ENDITEM, 
		"Name=__VIEWSTATEGENERATOR", "Value=C6B83A63", ENDITEM, 
		"Name=__EVENTVALIDATION", "Value=/wEdAAOWnP2BiipA7Vh6gBcOxe+ZSO+Wfz2F0XL9o5yAz8EC1b3Xi43vGp6xNVoz7qryOS/S7SlWgTcSbUWojoSNMoUrQT7bi9WP+udiADw7LOjM7g==", ENDITEM, 
		"Name=ctl00$head$txtMagicNo", "Value=1882784377", ENDITEM, 
		"Name=ctl00$head$btnStep2", "Value=Next", ENDITEM, 
		LAST);

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Status", 
		"0");

	web_url("LoadRunner_Correlation_Challenge_Exp.aspx_5", 
		"URL=http://loadrunnertips.com/LoadRunner_Correlation_Challenge_Exp.aspx?RQM=1649104177&RND=0.19235984635571723", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://loadrunnertips.com/LoadRunner_Correlation_Challenge_Exp.aspx", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}