vuser_end()
{
	lr_message("rrs:viewstate is %d characters long",strlen(lr_eval_string("{c_viewstate}")));
	lr_message("rrs:viewstategenerator is %d characters long",strlen(lr_eval_string("{c_viewstategenerator}")));
	lr_message("rrs:eventvalidation is %d characters long",strlen(lr_eval_string("{c_eventvalidation}")));

	return 0;
}
