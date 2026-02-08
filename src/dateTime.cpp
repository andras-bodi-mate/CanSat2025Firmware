#include "dateTime.hpp"

DateTime::DateTime(bool isValid, int year, int month, int day, int hour, int minute, int second, int millisecond):
isValid(isValid), year(year), month(month), day(day), hour(hour), minute(minute), second(second), millisecond(millisecond) {}