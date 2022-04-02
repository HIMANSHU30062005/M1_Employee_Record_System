#ifndef _EMPLOYEEMANAGEMENT_H_
#define _EMPLOYEEMANAGEMENT_H_

#include "add_record.h"
#include "delete_record.h"
#include "modify_record.h"
#include "display_record.h"

#endif

typedef struct emp
    {
        char Name[50]; ///name of employee
        int Age; /// age of employee
        char Address[50];//address of employee
        float Salary; /// salary of employee
    };