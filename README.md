# vugen-correlation-examples

# Summary
This repository contains two VuGen scripts, which contain correlations of increasing complexity. It also contains a PowerPoint presentation which explains correlation in general, and what is in these scripts in particular.

# Description
## Script 1: correlation_moderate
The first script, correlation_moderate, contains 3 correlations.

The first correlation, for c_magicno (Magic Number) is very simple.

The second correlation, for c_game is a bit more complicated. Design studio does find this correlation, but implements it with an ordinal selection which will not replay. The correlation as implemented finds the select value from the list. There is also code to modify the game in case there is an embedded space. This was discovered by recording the business process until a game with a space occurred.

The third correlation, for c_status is quite complicated. The status for 20 flights is returned. All 20 statuses are captured in a parameter array. Because the statuses captured do not match the status values used in the web_submit_form, an parameter array "submitstatus" is created. Then in the submit, there is an if statement controlled by the variable bruteForce. If it is 1 (true), all 20 status value parameters are used in a web_submit_form. If it is a 0 (false), a web_custom_request is created by appending the value fields into a buffer. In this custom request, correlated values for the VIEWSTATExxxx fields must also be used.

This third correlation requires a moderate understanding of C and use of the standard library to manipulate strings.

## Script 2: correlation_advanced
The second script, correlation_advanced, contains 2 correlations.

The first correlation is relatively simple, and correlations two field names, as opposed to field values.

The second correlation is somewhat tricky, but does exist in practice. The value to correlate is <b>not</b> returned by the server! Rather, it gets returned in two separate values which must be concatenated before being returned to the server.
