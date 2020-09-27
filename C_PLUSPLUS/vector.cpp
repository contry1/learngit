
"cout": 未声明的标识符(why 'cout' is not a member of 'std')
编译出现"cout": 未声明的标识符的错误

#include<iostream>
#include "stdafx.h"
#include<stdlib.h>

应把#include "stdafx.h"写在#include<iostream>的前面：

#include "stdafx.h"
#include<iostream>
#include<stdlib.h>

