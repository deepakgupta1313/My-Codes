cal:-write('Welcome to Airtel.'),nl,askForLandMobile.


askForLandMobile:-write('For Mobile Related Queries Press 1. For Landline related Queries Press 2.'),nl,getLandMobile(X).
getLandMobile(X):-read(X),((X==1)->mobileQueries;(checkLandQueries(X))).
checkLandQueries(X):-((X==2)->landQueries;invalidMobileLand).
mobileQueries:-write('Welcome to Airtel Mobile'),nl,askForOldOrNewMobile.
landQueries:-write('Welcome to Airtel Landline And Broadband'),nl,askForOldOrNewLand.
invalidMobileLand:-write('Invalid Option.'),nl,askForLandMobile.


askForOldOrNewMobile:-write('If you are an existing customer please Press 1 else Press 2.'),nl,getOldOrNewMobile(X).
getOldOrNewMobile(X):-read(X),((X==1)->existingCustomerMobile;(checkNewCustomerMobile(X))).
checkNewCustomerMobile(X):-((2==X)->newCustomerMobile;invalidOldNewMobile).
existingCustomerMobile:-write('Enter your phone number'),nl,getMobile(X).
newCustomerMobile:-write('Welcome'),nl,custCare.
invalidOldNewMobile:-write('Invalid Option.'),nl,askForOldOrNewMobile.
getMobile(X):-read(X),((customerTypePhone('Mobile',X))->(welcomeOldMobile(X));invalidMobile).
welcomeOldMobile(X):-getName(X,Y),nl,write('Welcome '),write(Y),write('.'),nl,nl,oldMainMobileOptions(X).
getName(X,Y):-(customerPhoneName(X,Y)).
invalidMobile:-write('Invalid Mobile Number.'),nl,existingCustomerMobile.
oldMainMobileOptions(X):-	write('Press 1 for Best Offers.'),nl,
							write('Press 2 for HelloTunes and Other Value Added Services.'),nl,
							write('Press 3 for Validity and Balance.'),nl,
							write('Press 4 for Mobile Internet'),nl,
							getMainMobileInput(X).
							
getMainMobileInput(X):-read(Y),checkMainMobileBestOffers(X,Y).
checkMainMobileBestOffers(X,Y):-((Y==1)->mobileBestOffersOptions(X);checkMainMobileVAS(X,Y)).
checkMainMobileVAS(X,Y):-((Y==2)->mobileVASOptions(X);checkMobileValBal(X,Y)).
checkMobileValBal(X,Y):-((Y==3)->mobileValBalOptions(X);checkMobileInternet(X,Y)).
checkMobileInternet(X,Y):-((Y==4)->mobileInternetOptions(X);invalidMainMobile(X,Y)).
invalidMainMobile(X):-write('Invalid Option.'),nl,oldMainMobileOptions(X).

		mobileBestOffersOptions(X):-write('Airtel has some special offers for you.'),nl,
									write('Full talktime on recharge of Rs.200 and validity of 60 days'),nl,
									write('Full talktime on recharge of Rs.400 and validity of 150 days'),nl,
									thank.
							

		mobileVASOptions(X):-		write('Press 1 to Start a Value Added Service.'),nl,
									write('Press 2 to Stop a Value Added Service.'),nl,
									write('Press 7 to Go to Previous Menu.'),nl,
									write('Press 8 to Go to Main Menu.'),nl,
									write('Press 9 to Speak to a Customer Care Representative directly.'),nl,
									getmobileVASInput(X).
									
				getmobileVASInput(X):-read(Y),checkMobileVASStart(X,Y).
				checkMobileVASStart(X,Y):-(Y==1->mobileVASStartOptions(X);checkMobileVASStop(X,Y)).
				checkMobileVASStop(X,Y):-(Y==2->mobileVASStopOptions(X);checkMobileVASPreMenu(X,Y)).
				checkMobileVASPreMenu(X,Y):-(Y==7->oldMainMobileOptions(X);checkMobileVASMainMenu(X,Y)).
				checkMobileVASMainMenu(X,Y):-(Y==8->oldMainMobileOptions(X);checkMobileVASCustCare(X,Y)).
				checkMobileVASCustCare(X,Y):-(Y==9->custCare;invalidMobileVAS(X)).
				invalidMobileVAS(X):-write('Invalid Option.'),nl,mobileVASOptions(X).
				
				
						mobileVASStartOptions(X):-	write('Press 1 to Start Hello Tunes.'),nl,
													write('Press 2 to Start Astrology.'),nl,
													write('Press 3 to Start Missed Call Alerts.'),nl,
													write('Press 4 to Start Job Alerts.'),nl,
													write('Press 7 to Go to Previous Menu.'),nl,
													write('Press 8 to Go to Main Menu.'),nl,
													write('Press 9 to Speak to a Customer Care Representative directly.'),nl,
													getmobileVASStartInput(X).
								
								getmobileVASStartInput(X):-read(Y),checkMobileVASStartHelloTunes(X,Y).
								checkMobileVASStartHelloTunes(X,Y):-(Y==1->mobileVASStartHT(X);checkMobileVASStartAstrology(X,Y)).
								checkMobileVASStartAstrology(X,Y):-(Y==2->mobileVASStartAstrology(X);checkMobileVASStartMissedCall(X,Y)).
								checkMobileVASStartMissedCall(X,Y):-(Y==3->mobileVASStartMissedCall(X);checkMobileVASStartJob(X,Y)).
								checkMobileVASStartJob(X,Y):-(Y==4->mobileVASStartJob(X);checkMobileVASStartPreMenu(X,Y)).
								checkMobileVASStartPreMenu(X,Y):-(Y==7->mobileVASOptions(X);checkMobileVASStartMainMenu(X,Y)).
								checkMobileVASStartMainMenu(X,Y):-(Y==8->oldMainMobileOptions(X);checkMobileVASStartCustCare(X,Y)).
								checkMobileVASStartCustCare(X,Y):-(Y==9->custCare;invalidMobileStartVAS(X)).
								invalidMobileStartVAS(X):-write('Invalid Option.'),nl,mobileVASStartOptions(X).
								
										mobileVASStartHT(X):-write('Hello Tune has been started on your number.'),nl,thank.
										mobileVASStartAstrology(X):-write('Astrology has been started on your number.'),nl,thank.
										mobileVASStartMissedCall(X):-write('Missed Call Alerts have been started on your number.'),nl,thank.
										mobileVASStartJob(X):-write('Job Alerts have been started on your number.'),nl,thank.
										
										
						mobileVASStopOptions(X):-	write('Press 1 to Stop Hello Tunes.'),nl,
													write('Press 2 to Stop Astrology.'),nl,
													write('Press 3 to Stop Missed Call Alerts.'),nl,
													write('Press 4 to Stop Job Alerts.'),nl,
													write('Press 7 to Go to Previous Menu.'),nl,
													write('Press 8 to Go to Main Menu.'),nl,
													write('Press 9 to Speak to a Customer Care Representative directly.'),nl,
													getmobileVASStopInput(X).
								
								getmobileVASStopInput(X):-read(Y),checkMobileVASStopHelloTunes(X,Y).
								checkMobileVASStopHelloTunes(X,Y):-(Y==1->mobileVASStopHT(X);checkMobileVASStopAstrology(X,Y)).
								checkMobileVASStopAstrology(X,Y):-(Y==2->mobileVASStopAstrology(X);checkMobileVASStopMissedCall(X,Y)).
								checkMobileVASStopMissedCall(X,Y):-(Y==3->mobileVASStopMissedCall(X);checkMobileVASStopJob(X,Y)).
								checkMobileVASStopJob(X,Y):-(Y==4->mobileVASStopJob(X);checkMobileVASStopPreMenu(X,Y)).
								checkMobileVASStopPreMenu(X,Y):-(Y==7->mobileVASOptions(X);checkMobileVASStopMainMenu(X,Y)).
								checkMobileVASStopMainMenu(X,Y):-(Y==8->oldMainMobileOptions(X);checkMobileVASStopCustCare(X,Y)).
								checkMobileVASStopCustCare(X,Y):-(Y==9->custCare;invalidMobileStopVAS(X)).
								invalidMobileStopVAS(X):-write('Invalid Option.'),nl,mobileVASStopOptions(X).
								
										mobileVASStopHT(X):-write('Hello Tune has been stopped on your number.'),nl,thank.
										mobileVASStopAstrology(X):-write('Astrology has been stopped on your number.'),nl,thank.
										mobileVASStopMissedCall(X):-write('Missed Call Alerts have been stopped on your number.'),nl,thank.
										mobileVASStopJob(X):-write('Job Alerts have been stopped on your number.'),nl,thank.
										
										
		mobileValBalOptions(X):-write('Press 1 to check Balance'),nl,
								write('Press 2 to check Validity'),nl,
								write('Press 7 to Go to Previous Menu.'),nl,
								write('Press 8 to Go to Main Menu.'),nl,
								write('Press 9 to Speak to a Customer Care Representative directly.'),nl,
								getValBalInput(X).
										
										
										getValBalInput(X):-read(Y),checkMobileBal(X,Y).
										checkMobileBal(X,Y):-(Y==1->mobileBal(X);checkMobileVal(X,Y)).
										checkMobileVal(X,Y):-(Y==2->mobileVal(X);checkMobileValBalPreMenu(X,Y)).
										checkMobileValBalPreMenu(X,Y):-(Y==7->oldMainMobileOptions(X);checkMobileValBalMainMenu(X,Y)).
										checkMobileValBalMainMenu(X,Y):-(Y==8->oldMainMobileOptions(X);checkMobileValBalCustCare(X,Y)).
										checkMobileValBalCustCare(X,Y):-(Y==9->custCare;invalidMobileValBal(X)).
										invalidMobileValBal(X):-write('Invalid Option.'),nl,mobileValBalOptions(X).
										
												mobileBal(X):-getMobileBal(X,Y),write('Your Balance is Rs.'),write(Y),write('.'),nl.
														getMobileBal(X,Y):-customerPhoneBalance(X,Y).
														
												mobileVal(X):-getMobileVal(X,Y),write('Your Validity is '),write(Y),write(' days.'),nl.
														getMobileVal(X,Y):-customerPhoneValidity(X,Y).
				
		
		mobileInternetOptions(X):-	write('Press 1 to Start Mobile Internet.'),nl,
									write('Press 2 to Stop Mobile Internet.'),nl,
									write('Press 7 to Go to Previous Menu.'),nl,
									write('Press 8 to Go to Main Menu.'),nl,
									write('Press 9 to Speak to a Customer Care Representative directly.'),nl,
									getMobileInternetInput(X).
									
											getMobileInternetInput(X):-read(Y),checkMobileInternetStart(X,Y).
											checkMobileInternetStart(X,Y):-((Y==1)->mobileInternetStart(X);checkMobileInternetStop(X,Y)).
											checkMobileInternetStop(X,Y):-((Y==2)->mobileInternetStop(X);checkMobileInternetPreMenu(X,Y)).
											checkMobileInternetPreMenu(X,Y):-(Y==7->oldMainMobileOptions(X);checkMobileInternetMainMenu(X,Y)).
											checkMobileInternetMainMenu(X,Y):-(Y==8->oldMainMobileOptions(X);checkMobileInternetCustCare(X,Y)).
											checkMobileInternetCustCare(X,Y):-(Y==9->custCare;invalidMobileInternet(X)).
											invalidMobileInternet(X):-write('Invalid Option.'),nl,mobileInternetOptions(X).

													mobileInternetStart(X):-write('Mobile Internet has been started on your number.'),nl,thank.
													mobileInternetStop(X):-write('Mobile Internethas been stopped on your number.'),nl,thank.

												
	




askForOldOrNewLand:-write('If you are an existing customer please Press 1 else Press 2.'),nl,getOldOrNewLand(X).
getOldOrNewLand(X):-read(X),((X==1)->existingCustomerLand;(checkNewCustomerLand(X))).
checkNewCustomerLand(X):-((2==X)->newCustomerLand;invalidOldNewLand).
existingCustomerLand:-write('Enter your phone number'),nl,getLand(X).
newCustomerLand:-write('Welcome'),nl,custCare.
invalidOldNewLand:-write('Invalid Option.'),nl,askForOldOrNewLand.
getLand(X):-read(X),((customerTypePhone('LandLine',X))->(welcomeOldLand(X));invalidLand).
welcomeOldLand(X):-getName(X,Y),nl,write('Welcome '),write(Y),write('.'),nl,nl,oldMainLandOptions(X).
getName(X,Y):-(customerPhoneName(X,Y)).
invalidLand:-write('Invalid LandLine Number.'),nl,existingCustomerLand.
oldMainLandOptions(X):-	write('Press 1 for Best Offers.'),nl,
							write('Press 2 for HelloTunes.'),nl,
							write('Press 3 for Broadband Related Queries.'),nl,
							getMainLandInput(X).
							
getMainLandInput(X):-read(Y),checkMainLandBestOffers(X,Y).
checkMainLandBestOffers(X,Y):-((Y==1)->landBestOffersOptions(X);checkMainLandHT(X,Y)).
checkMainLandHT(X,Y):-((Y==2)->landHTOptions(X);checkLandBroadband(X,Y)).
checkLandBroadband(X,Y):-((Y==3)->landBroadbandOptions(X);invalidMainLand(X,Y)).
invalidMainLand(X):-write('Invalid Option.'),nl,oldMainLandOptions(X).

		landBestOffersOptions(X):-write('Airtel has no special offers for you right now. Please check again later'),nl,
									thank.
							

		landHTOptions(X):-		write('Press 1 to Start Hello Tunes.'),nl,
									write('Press 2 to Stop Hello Tunes.'),nl,
									write('Press 7 to Go to Previous Menu.'),nl,
									write('Press 8 to Go to Main Menu.'),nl,
									write('Press 9 to Speak to a Customer Care Representative directly.'),nl,
									getlandHTInput(X).
									
				getlandHTInput(X):-read(Y),checkLandHTStart(X,Y).
				checkLandHTStart(X,Y):-(Y==1->landHTStart(X);checkLandHTStop(X,Y)).
				checkLandHTStop(X,Y):-(Y==2->landHTStop(X);checkLandHTPreMenu(X,Y)).
				checkLandHTPreMenu(X,Y):-(Y==7->oldMainLandOptions(X);checkLandHTMainMenu(X,Y)).
				checkLandHTMainMenu(X,Y):-(Y==8->oldMainLandOptions(X);checkLandHTCustCare(X,Y)).
				checkLandHTCustCare(X,Y):-(Y==9->custCare;invalidLandHT(X)).
				invalidLandHT(X):-write('Invalid Option.'),nl,landHTOptions(X).
				
				
								
						landHTStart(X):-write('Hello Tune has been started on your number.'),nl,thank.
						landHTStop(X):-write('Hello Tune has been stopped on your number.'),nl,thank.
										
										
										
		
		landBroadbandOptions(X):-	write('Press 1 to get Broadband.'),nl,
									write('Press 2 to cancel Broadband.'),nl,
									write('Press 7 to Go to Previous Menu.'),nl,
									write('Press 8 to Go to Main Menu.'),nl,
									write('Press 9 to Speak to a Customer Care Representative directly.'),nl,
									getLandBroadbandInput(X).
									
											getLandBroadbandInput(X):-read(Y),checkLandBroadbandStart(X,Y).
											checkLandBroadbandStart(X,Y):-((Y==1)->landBroadbandStart(X);checkLandBroadbandStop(X,Y)).
											checkLandBroadbandStop(X,Y):-((Y==2)->landBroadbandStop(X);checkLandBroadbandPreMenu(X,Y)).
											checkLandBroadbandPreMenu(X,Y):-(Y==7->oldMainLandOptions(X);checkLandBroadbandMainMenu(X,Y)).
											checkLandBroadbandMainMenu(X,Y):-(Y==8->oldMainLandOptions(X);checkLandBroadbandCustCare(X,Y)).
											checkLandBroadbandCustCare(X,Y):-(Y==9->custCare;invalidLandBroadband(X)).
											invalidLandBroadband(X):-write('Invalid Option.'),nl,landBroadbandOptions(X).

													landBroadbandStart(X):-custCare.
													landBroadbandStop(X):-custCare.









customerTypePhone('Mobile',8968781723).
customerPhoneName(8968781723,'Deepak').
customerPhoneValidity(8968781723,30).
customerPhoneBalance(8968781723,200).
customerPhoneHelloTune(8968781723,1).
customerPhoneAstrology(8968781723,1).
customerPhoneMissedCallAlert(8968781723,0).
customerPhoneJobAlert(8968781723,0).
customerPhoneMobileInternet(8968781723,1).

customerTypePhone('LandLine',4301589).
customerPhoneName(4301589,'Mintoo').
customerPhoneHelloTune(4301589,0).
customerPhoneBroadband(4301589,0).
customerOutstandingDues(4301589,100).







thank:-write('Thank you for using Airtel IVR'),nl.
custCare:-	thank,
			write('You will be shortly connected an Airtel Customer Care Representative.'),nl.
			