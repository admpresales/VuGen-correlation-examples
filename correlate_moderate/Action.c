Action()
{
	char c_paramName[128];
	char submitfield[128];
	char submitStatus[128];
	char buf[128];
	char* bufp;
	int i;
	int bruteForce = 0; // 0=> False, all else true - used to show two possible ways for final correlation
	
	web_global_verification("text=Error Try again", // make sure we get to the end
	                        LAST);
	
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
	web_reg_save_param_regexp("paramname=c_magicno1",  // show using regex
	                          "regexp=<span id=\"head_lblMagicno\"><strong>\\n*(\\d+)\\n</span>",
	                          LAST);

	web_reg_save_param_ex("paramname=c_magicno12",  // or left boundary, offset and length
	                          "lb=<span id=\"head_lblMagicno\"><strong>",
	                          "saveOffset=5",
	                          "saveLen=4",
	                          LAST);

	web_submit_form("LoadRunner_Correlation_Challenge_Mod.aspx_2",
		"Snapshot=t5.inf", 
		ITEMDATA, 
		"Name=ctl00$head$btnStart", "Value=Start", ENDITEM, 
		LAST);

	/* number */

//<option value='Lacrosse' id='DD1313' selected='selected'  class='DD1313'>Lacrosse</option>

	web_reg_save_param_regexp(
		"ParamName=c_game",
		"RegExp=option value='([\\w| ]+)' id='DD\\d*' selected", // some of the sports have embedded spaces, hence the [ | ] syntax
		LAST);	
		
	web_reg_find("text=Leave the drop-down list set to its default value, and press Next",
             LAST);
             
	sleep(1*1000);
	web_submit_form("LoadRunner_Correlation_Challenge_Mod.aspx_3", 
		"Snapshot=t6.inf", 
		ITEMDATA, 
		"Name=ctl00$head$txtMacigNo", "Value={c_magicno12}", ENDITEM, 
		"Name=ctl00$head$btnNext", "Value=Next", ENDITEM, 
		LAST);

	/* drop-down */

//                <span id="head_lblstatus6">Delay</span>\r\n
	web_reg_save_param_ex("paramName=c_status", // this capture works, but pre-pends the status with N<
                   "lb=head_lblstatus",
                   "rb=</span>",
                   "ordinal=All",
                   LAST);                   
	web_reg_save_param_regexp("paramName=c_status_regexp_xx", // thiss grabs just the status
                   "regexp=head_lblstatus\\d+\">([\\w| ]+)</span>",
                   "ordinal=all",
                   LAST);
	web_set_max_html_param_len("2048");
    web_reg_save_param_ex("paramname=c_viewstate",
                   "LB=id=\"__VIEWSTATE\" value=\"/",
                   "RB=\"",
                   LAST);          
    web_reg_save_param_ex("paramName=c_viewstategenerator",
                   "LB=id=\"__VIEWSTATEGENERATOR\" value=\"",
                   "RB=\"",
                   LAST);
                   
    web_reg_save_param_ex("paramname=c_eventvalidation",
                   "LB=id=\"__EVENTVALIDATION\" value=\"/",
                   "RB==\"",
                   LAST);
                   
/*- following changes " " to "+', but site wants %2 30              
   web_convert_param("c_game",
                  "SourceEncoding=PLAIN",
                  "TargetEncoding=URL",
                  LAST);
*/
	bufp = replaceWord(lr_eval_string("{c_game}")," ","%20");
	lr_save_string(bufp,"c_game");
	
	web_reg_find("text=Select All the Airline whoes Flight Status is On Time and Click Next",
             LAST);

	web_url("LoadRunner_Correlation_Challenge_Mod.aspx_4",
		"URL=http://loadrunnertips.com/LoadRunner_Correlation_Challenge_Mod.aspx?dd=1&game={c_game}",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://loadrunnertips.com/LoadRunner_Correlation_Challenge_Mod.aspx",
		"Snapshot=t7.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=http://detectportal.firefox.com/success.txt", ENDITEM,
		LAST);

	/* on time */
	for (i=1;i<=20;i++) { //set the 20 status values for use in simple below
			sprintf (c_paramName, "{c_status_%d}",i);
			sprintf (submitStatus, "submitStatus_%d",i);
			if (strstr(lr_eval_string(c_paramName), "Delay")){
			    	lr_save_string ("<OFF>",submitStatus);
			} else {
			    	lr_save_string ("on",submitStatus);
			}
	     }

	web_reg_find("text=Correlation Challenge Completed",
	             LAST);
	           
	if (bruteForce) {
// brute force, i.e., replace all 20 references. would be painful if there were hundreds
// Note: because a web_submit_form - no need to correlate the VIEWSTATE and stuff
// that is the kind of thing that web_submit_form does for you "automagically"
		web_submit_form("LoadRunner_Correlation_Challenge_Mod.aspx_5", 
			"Snapshot=t8.inf", 
			ITEMDATA, 
			"Name=ctl00$head$chk1", "Value={submitStatus_1}", ENDITEM, 
			"Name=ctl00$head$chk2", "Value={submitStatus_2}", ENDITEM, 
			"Name=ctl00$head$chk3", "Value={submitStatus_3}", ENDITEM, 
			"Name=ctl00$head$chk4", "Value={submitStatus_4}", ENDITEM, 
			"Name=ctl00$head$chk5", "Value={submitStatus_5}", ENDITEM, 
			"Name=ctl00$head$chk6", "Value={submitStatus_6}", ENDITEM, 
			"Name=ctl00$head$chk7", "Value={submitStatus_7}", ENDITEM, 
			"Name=ctl00$head$chk8", "Value={submitStatus_8}", ENDITEM, 
			"Name=ctl00$head$chk9", "Value={submitStatus_9}", ENDITEM, 
			"Name=ctl00$head$chk10", "Value={submitStatus_10}", ENDITEM, 
			"Name=ctl00$head$chk11", "Value={submitStatus_11}", ENDITEM, 
			"Name=ctl00$head$chk12", "Value={submitStatus_12}", ENDITEM, 
			"Name=ctl00$head$chk13", "Value={submitStatus_13}", ENDITEM, 
			"Name=ctl00$head$chk14", "Value={submitStatus_14}", ENDITEM, 
			"Name=ctl00$head$chk15", "Value={submitStatus_15}", ENDITEM, 
			"Name=ctl00$head$chk16", "Value={submitStatus_16}", ENDITEM, 
			"Name=ctl00$head$chk17", "Value={submitStatus_17}", ENDITEM, 
			"Name=ctl00$head$chk18", "Value={submitStatus_18}", ENDITEM, 
			"Name=ctl00$head$chk19", "Value={submitStatus_19}", ENDITEM, 
			"Name=ctl00$head$chk20", "Value={submitStatus_20}", ENDITEM, 
			"Name=ctl00$head$btnNext3", "Value=Next", ENDITEM, 
			LAST);
	} else {
		/* recording. Got this be generating a script with recording options of url based script -> custom requests only
		Note that here - the VIEWSTATE is explict, so must be correlated
		web_custom_request("LoadRunner_Correlation_Challenge_Mod.aspx_5", 
			"URL=http://loadrunnertips.com/LoadRunner_Correlation_Challenge_Mod.aspx?dd=1&game={c_game}", 
			"Method=POST", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://loadrunnertips.com/LoadRunner_Correlation_Challenge_Mod.aspx?dd=1&game={c_game}", 
			"Snapshot=t13.inf", 
			"Mode=HTTP", 
			"Body=__VIEWSTATE="
			"%2FwEPDwUJOTg3MDg5NjY4ZBgBBR5fX0NvbnRyb2xzUmVxdWlyZVBvc3RCYWNrS2V5X18WFAUPY3RsMDAkaGVhZCRjaGsxBQ9jdGwwMCRoZWFkJGNoazIFD2N0bDAwJGhlYWQkY2hrMwUPY3RsMDAkaGVhZCRjaGs0BQ9jdGwwMCRoZWFkJGNoazUFD2N0bDAwJGhlYWQkY2hrNgUPY3RsMDAkaGVhZCRjaGs3BQ9jdGwwMCRoZWFkJGNoazgFD2N0bDAwJGhlYWQkY2hrOQUQY3RsMDAkaGVhZCRjaGsxMAUQY3RsMDAkaGVhZCRjaGsxMQUQY3RsMDAkaGVhZCRjaGsxMgUQY3RsMDAkaGVhZCRjaGsxMwUQY3RsMDAkaGVhZCRjaGsxNAUQY3RsMDAkaGVhZCRjaGsxNQUQY3RsMDAkaGVhZCRjaGsxNgUQY3RsMDAkaGVhZCRjaGsxNwUQY3RsMDAkaGVhZCRjaGsxOAUQY3RsMDAk"
			"aGVhZCRjaGsxOQUQY3RsMDAkaGVhZCRjaGsyML%2FzVsByswEHc52Mrd4hGSfbZNhwNACZA%2Bp2BQP3LADO&" 
			"__VIEWSTATEGENERATOR=3074961D&" 
			"__EVENTVALIDATION=%2FwEdABZGzRDLAmWNiba6xDvO69AAqasbxwl7lgdZZfZ2n%2BoFBQVQb%2FBqIrnuBsiTd5SBX0XDYFHBMur5v1vZ4LUwZUXEv1bMxkD35JfEKTUHLZw4URiuU4nLTwtj%2Fr43949QF%2FfcXs3H4McaH100kUT9gcPbmpgAqjKGNuaeCinRuZ1fUy%2BAnrQ09DAotZNMecAuJqp7WQG8SNPlN0mV%2BBwfjWNo1u1qRUoE0ucmhZnEUyRDxJcIA7A2BTvsdZNVrY2UTuZixHoyjomtObKrCt06E5%2FUAoxFdFd6aX6eQs9i0oSTXDkt%2BDo6wOIA4KwaXE0pUgA2isLFBHeYufrtFtgXd6f0DGIM5YFnsJoM%2BHWSXfRSONHx4ZdtIVVepNuIcMSoJKpEnOUHlLp%2BoSuQ44YhcKDN8B20tHcNPS9okHrSEPNbXouIr9iCQfCWk3E3COVI0FitjCG6HyklgWzfDmV0vuRMYpGA"
			"GN1%2BenLDGa3Jxpv7JGRgtbsLvclOPRToYdEOT0A%3D&" 
			"ctl00%24head%24chk1=on&" 
			"ctl00%24head%24chk4=on&" 
			"ctl00%24head%24chk5=on&" 
			"ctl00%24head%24chk12=on&" 
			"ctl00%24head%24chk15=on&" 
			"ctl00%24head%24btnNext3=Next",
			LAST);
*/
	char buffer[4096]; // this will contain the body to post
	char curStat[32];
	char curField[64];

	memset(buffer,0,4096); // need to clear, or second iteration will concatenate

	// now start creating the body
	// start with VIEWSTATE
	strcat(buffer,"__VIEWSTATE=%2F");
	
	web_convert_param("c_viewstate",
                  "SourceEncoding=PLAIN",
                  "TargetEncoding=URL",
                  LAST);

	strcat(buffer,lr_eval_string("{c_viewstate}"));
	strcat(buffer,"&");
	
	// next field
	strcat(buffer,"__VIEWSTATEGENERATOR=");
	strcat(buffer,lr_eval_string("{c_viewstategenerator}"));
	strcat(buffer,"&");
	
	// another field
	web_convert_param("c_eventvalidation", // raw value has ' + ' ' / ', and other special characters
                  "SourceEncoding=PLAIN",
                  "TargetEncoding=URL",
                  LAST);
	
	strcat(buffer,"__EVENTVALIDATION=%2F");
	strcat(buffer,lr_eval_string("{c_eventvalidation}"));
	strcat(buffer,"%3d&");
	
	// now create the part that changes, the fields that are set to on
	for (i=1;i<=20;i++) { // as seen above, in custom request, only need to post the ontime values
		sprintf(submitStatus,"{c_status_%d}",i);
		sprintf(curStat,lr_eval_string(submitStatus)); // curstat string now contains the status of this field
		if (strstr(curStat,"On Time")) { // on time, add to the post
		   	sprintf(curField,"ctl00%%24head%%24chk%d=on&",i); // it is on time, so add the <field>=on to curField
	       	strcat(buffer,curField); // and add to buffer. This could be done in one line
		}
	}

	strcat(buffer, "ctl00%24head%24btnNext3=Next"); // the last field
	lr_save_string(buffer,"body");  // save to a param to make easy to use in following request
	
	web_custom_request("LoadRunner_Correlation_Challenge_Mod.aspx_5",
			"URL=http://loadrunnertips.com/LoadRunner_Correlation_Challenge_Mod.aspx?dd=1&game={c_game}", 
			"Method=POST", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://loadrunnertips.com/LoadRunner_Correlation_Challenge_Mod.aspx?dd=1&game={c_game}", 
			"Snapshot=t13.inf", 
			"Mode=HTTP",
			"Body={body}",
			LAST);

	}
	return 0;
}