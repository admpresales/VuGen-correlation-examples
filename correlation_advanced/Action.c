Action()
{

	int my_magicNo;
	char s_myMagicNo[32];
//	web_set_sockets_option("SSL_VERSION", "TLS1.2");

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

	// input name="ctl00$head$QNo1.0" type="text" id="head_QNo1.0
	web_reg_save_param_ex("paramname=c_xxx",
	                      "lb=name=\"ctl00$head",
	                      "rb=type=\"text\" id=\"head_Q",
	                      LAST);
		
	web_reg_save_param_regexp("paramname=c_fieldName",
	                         "regexp=name=\"(ctl00.*)\" type=\"text\" id=\"head_Q",
	                         LAST);


	web_submit_form("LoadRunner_Correlation_Challenge_Exp.aspx_2",
		"Snapshot=t15.inf", 
		ITEMDATA, 
		"Name=ctl00$head$btnStart", "Value=Start", ENDITEM, 
		LAST);
	
/*Correlation comment - Do not change!  Original value='/wEdAAOWnP2BiipA7Vh6gBcOxe' Name ='CorrelationParameter' Type ='ResponseBased'
	web_reg_save_param_regexp("ParamName=CorrelationParameter",
		"RegExp=id=\"__EVENTVALIDATION\"\\ value=\"(.*?)\\+Z6PRGMN1wyLzpD3MQpHTtazrXPBqUZcs4yqSWpp6",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);
		above was created by design studio
		rrs:	it is stupid
		*/

	web_reg_save_param_regexp("ParamName=__EVENTVALIDATION",
		"RegExp=id=\"__EVENTVALIDATION\"\\ value=\"(.*?)\" />",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);
		//or
	web_reg_save_param_attrib(
		"ParamName=__EVENTVALIDATION_rrs",
		"TagName=input",
		"Extract=value",
		"Name=__EVENTVALIDATION",
		"Id=__EVENTVALIDATION",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/LoadRunner_Correlation_Challenge_Exp.aspx*",
		LAST);	

	web_reg_save_param_attrib(
		"ParamName=__VIEWSTATE",
		"TagName=input",
		"Extract=value",
		"Name=__VIEWSTATE",
		"Id=__VIEWSTATE",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/LoadRunner_Correlation_Challenge_Exp.aspx*",
		LAST);	

/*Correlation comment - Do not change!  Original value='C6B83A63' Name ='__VIEWSTATEGENERATOR' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=__VIEWSTATEGENERATOR",
		"TagName=input",
		"Extract=value",
		"Name=__VIEWSTATEGENERATOR",
		"Id=__VIEWSTATEGENERATOR",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/LoadRunner_Correlation_Challenge_Exp.aspx*",
		LAST);


	web_reg_save_param_ex("paramname=c_offset",
		                      "lb=head_divDDL\"><strong>",
		                      "saveOffset=5",
		                      "saveLen=5",
		                      LAST);
	
	web_reg_save_param_ex("paramname=c_magicNo",
		                      "lb=ctl00$head$btnStep2\" value=\"Next\" onclick=\"return dd(&#39;",
		                      "rb=&#39",
		                      LAST);
	web_reg_find("text=Enter the following number in the field below and press Next",
		             LAST);
		                       
	web_submit_form("LoadRunner_Correlation_Challenge_Exp.aspx_3", 
		"Snapshot=t16.inf", 
		ITEMDATA, 
		"Name={c_fieldName}", "Value=Alwar", ENDITEM, // was recorded as ctl00$head$QNo1.7
		"Name=ctl00$head$btnNext", "Value=Next", ENDITEM, 
		EXTRARES, 
//		"Url=/WebResource.axd?d=Dni4Dwp2sE7BkxnwJrEAA5649Tlmnpvwn2La2DRwkPVt5D7zaVMO-EzSoZ_dVp6PBIJvfHbzOMQZeZkiuwwsKjfi5gBPV8iFZodpTRMsMug1&t=636765212300000000", ENDITEM, 
//		"Url=/WebResource.axd?d=_ik9MG88W60F3HCI3_iYhWbegkhYG7ydNd13f4OiDs4o4SXDkA3axp76aGF6nX2u8QN6h5kURIRHRFRTQRGwTHWg_sLQ5n4rRo3B6oaZXaI1&t=636765212300000000", ENDITEM, 
		LAST);
		                      
	my_magicNo =  atoi(lr_eval_string("{c_offset}")) + atoi(lr_eval_string("{c_magicNo}"));
	sprintf(s_myMagicNo,"%d",my_magicNo);
	lr_save_string(s_myMagicNo,"c_submitted_magic_no");

	web_reg_find("text=Click on Next",
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
		"Name=__VIEWSTATE", "Value={__VIEWSTATE}", ENDITEM,
		"Name=__VIEWSTATEGENERATOR", "Value={__VIEWSTATEGENERATOR}", ENDITEM,
		"Name=__EVENTVALIDATION", "Value={__EVENTVALIDATION}", ENDITEM,
		"Name=ctl00$head$txtMagicNo", "Value={c_submitted_magic_no}", ENDITEM,
		"Name=ctl00$head$btnStep2", "Value=Next", ENDITEM,
		LAST);

	web_reg_find("text=What is Correlation in Load Runner",
             LAST);
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