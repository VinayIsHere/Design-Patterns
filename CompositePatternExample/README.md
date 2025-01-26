Here is the example structure:

[On/Off]Root
	-[On/Off] Group 1
		-[On/Off] Item 1
		-[On/Off] Item 2
	-[On/Off] Group 2
		-[On/Off] Item 3
		-[On/Off] Item 4

What we have to implement is:
	* Users can create tree hierarchy with nth depth.
	* Turning ON Group 1 should Turn On Item 1 and Item 2 also.
	* Turning OFF Group 1 should Uncheck Item 1 & Item 2 also.
	* If Group 1 is on & Group 2 in off, Root should remain turn off. It can become On when both group 1 and group 2 is on.