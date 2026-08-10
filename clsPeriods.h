#pragma once
#include"clsDate.h"


class clsPeriod
{
public:

	clsDate StartDate;
	clsDate EndDate;

	clsPeriod(clsDate StartDate, clsDate DateTo)
	{
		this->StartDate = StartDate;
		this->EndDate = DateTo;


	};


	void Print()
	{
		cout << "Period Start: ";
		StartDate.Print();


		cout << "Period End: ";
		EndDate.Print();


	}


	static bool IsPeriodsOverLap(clsPeriod Period1, clsPeriod Period2) {

		if (clsDate::IsDate1AfterDate2(Period2.StartDate, Period1.EndDate) || clsDate::IsDate1AfterDate2(Period1.StartDate, Period2.EndDate)) {
			return false;
		}
		else
			return true;

	}

	bool IsPeriodsOverLap(clsPeriod Period2) {
		return IsPeriodsOverLap(*this, Period2);
	}


	static short PeriodLengthInDays(clsPeriod Period, bool EndDate = false) {

		return clsDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, EndDate);
	}

	short PeriodLengthInDays() {

		return PeriodLengthInDays(*this);
	}



	static bool IsDateWhitinPeriod(clsPeriod Period, clsDate Date) {
		return (clsDate::IsDate1BeforeDate2(Period.StartDate, Date) && clsDate::IsDate1AfterDate2(Period.EndDate, Date));
	};

	bool IsDateWhitinPeriod(clsDate Date) {
		return IsDateWhitinPeriod(*this, Date);
	};



	static short CountOverLapDays(clsPeriod Period1, clsPeriod Period2) {

		int Period1Lenght = PeriodLengthInDays(Period1, true);
		int Period2Lenght = PeriodLengthInDays(Period2, true);
		int OverLapDays = 0;


		if (!IsPeriodsOverLap(Period1, Period2)) {
			return 0;
		}


		if (Period1Lenght < Period2Lenght) {

			while (clsDate::IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate)) {

				if (IsDateWhitinPeriod(Period2, Period1.StartDate)) {

					OverLapDays++;

				}

				Period1.StartDate = clsDate::AddOneDay(Period1.StartDate);
			}
		}
		else {
			while (clsDate::IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate)) {

				if (IsDateWhitinPeriod(Period1, Period2.StartDate)) {
					OverLapDays++;
				}

				Period2.StartDate = clsDate::AddOneDay(Period2.StartDate);
			}
		}


		return OverLapDays;
	};


	short CountOverLapDays(clsPeriod Period2) {

		return CountOverLapDays(*this, Period2);
	};



	
};