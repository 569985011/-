#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2019-02-06 12:15:44
# @Author  : Chauncy (chauncy523@gmail.com)
# @Link    : 
# @Version : $Id$
import requests
import json

headers = {
'Content-Type': 'application/json',
'Cookie': 'PHPSESSID=d15e0b39eada5c4fa0bc4eff6be4bf6e; clientId=5c579eed95d98; pgv_pvi=2990812160; pgv_si=s1190974464; yfx_c_g_u_id_10000002=_ck19020410094210861123857863477; logtype=20; login_username=350301199407010010; skey=04fb2e596297713c720554a719df556c; yfx_f_l_v_t_10000002=f_t_1549246182074__r_t_1549246182074__v_t_1549583215332__r_c_56',

'DNT': 1,
'Host': 'e.gtfund.com',
'Referer': 'https://e.gtfund.com/etrade/User/jijinhistory',
'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36',
'X-Requested-With': 'XMLHttpRequest',

}
payloaddata={
'api': 'trade.history.application.list.with.total',
'params': {
	'page': 5, 
	'perPage': 10, 
	'since': "2019-01-08", 
	'until': "2019-02-11", 
	'fundCode': 'null',
	}
}

r=requests.post('https://e.gtfund.com/Etrade/Public/cochin',json.dumps(payloaddata),headers=headers)

print (r.getreader())
