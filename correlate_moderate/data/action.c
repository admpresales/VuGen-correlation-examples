Action()
{

	web_url("success.txt", 
		"URL=http://detectportal.firefox.com/success.txt", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t1.inf", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	lr_think_time(4);

	web_url("success.txt_2", 
		"URL=http://detectportal.firefox.com/success.txt", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t2.inf", 
		LAST);

	lr_think_time(5);

	web_url("success.txt_3", 
		"URL=http://detectportal.firefox.com/success.txt", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t3.inf", 
		LAST);

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("LoadRunner_Correlation_Challenge_Mod.aspx", 
		"URL=http://loadrunnertips.com/LoadRunner_Correlation_Challenge_Mod.aspx", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=http://detectportal.firefox.com/success.txt", "Referer=", ENDITEM, 
		"Url=/img/images.jpg", ENDITEM, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	/* start */

	lr_think_time(19);

	web_submit_form("LoadRunner_Correlation_Challenge_Mod.aspx_2", 
		"Snapshot=t5.inf", 
		ITEMDATA, 
		"Name=ctl00$head$btnStart", "Value=Start", ENDITEM, 
		LAST);

	/* number */

	lr_think_time(12);

	web_submit_form("LoadRunner_Correlation_Challenge_Mod.aspx_3", 
		"Snapshot=t6.inf", 
		ITEMDATA, 
		"Name=ctl00$head$txtMacigNo", "Value=2000", ENDITEM, 
		"Name=ctl00$head$btnNext", "Value=Next", ENDITEM, 
		LAST);

	/* drop-down */

	web_revert_auto_header("DNT");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	lr_think_time(8);

	web_url("LoadRunner_Correlation_Challenge_Mod.aspx_4", 
		"URL=http://loadrunnertips.com/LoadRunner_Correlation_Challenge_Mod.aspx?dd=1&game=Badminton", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://loadrunnertips.com/LoadRunner_Correlation_Challenge_Mod.aspx", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=http://detectportal.firefox.com/success.txt", "Referer=", ENDITEM, 
		LAST);

	/* on time */

	web_add_header("DNT", 
		"1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(6);

	web_submit_form("LoadRunner_Correlation_Challenge_Mod.aspx_5", 
		"Snapshot=t8.inf", 
		ITEMDATA, 
		"Name=ctl00$head$chk1", "Value=<OFF>", ENDITEM, 
		"Name=ctl00$head$chk2", "Value=on", ENDITEM, 
		"Name=ctl00$head$chk3", "Value=<OFF>", ENDITEM, 
		"Name=ctl00$head$chk4", "Value=<OFF>", ENDITEM, 
		"Name=ctl00$head$chk5", "Value=on", ENDITEM, 
		"Name=ctl00$head$chk6", "Value=<OFF>", ENDITEM, 
		"Name=ctl00$head$chk7", "Value=<OFF>", ENDITEM, 
		"Name=ctl00$head$chk8", "Value=<OFF>", ENDITEM, 
		"Name=ctl00$head$chk9", "Value=<OFF>", ENDITEM, 
		"Name=ctl00$head$chk10", "Value=<OFF>", ENDITEM, 
		"Name=ctl00$head$chk11", "Value=on", ENDITEM, 
		"Name=ctl00$head$chk12", "Value=<OFF>", ENDITEM, 
		"Name=ctl00$head$chk13", "Value=<OFF>", ENDITEM, 
		"Name=ctl00$head$chk14", "Value=<OFF>", ENDITEM, 
		"Name=ctl00$head$chk15", "Value=<OFF>", ENDITEM, 
		"Name=ctl00$head$chk16", "Value=<OFF>", ENDITEM, 
		"Name=ctl00$head$chk17", "Value=on", ENDITEM, 
		"Name=ctl00$head$chk18", "Value=on", ENDITEM, 
		"Name=ctl00$head$chk19", "Value=<OFF>", ENDITEM, 
		"Name=ctl00$head$chk20", "Value=<OFF>", ENDITEM, 
		"Name=ctl00$head$btnNext3", "Value=Next", ENDITEM, 
		LAST);

	return 0;
}