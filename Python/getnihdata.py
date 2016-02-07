# -*- coding: utf-8 -*-
"""
Created on Tue Feb  2 16:20:56 2016

File Name:     
Description:   This program retrieves the NIH data for NIHM institute.
Inputs:        Last Name, First Name
Output:        Data available for the given name.
Author:        Subhash C Thakur

"""

import requests
import lxml.html as lh


def nih_data(lname, fname):
    url = 'https://ned.nih.gov'
 
    form_data = {
        'ctl00$ContentPlaceHolder$txtLastName': lname,
        'ctl00$ContentPlaceHolder$txtFirstName': fname,
        'ctl00$ContentPlaceHolder$ddlIC': 'NIMH - National Institute of Mental Health',
    }

    response = requests.post(url, data=form_data)

    print(response.content)
    tree = lh.document_fromstring(response.content)
    print(tree)

    #return tree.xpath("//b[text()=$caption]", caption=caption)[0].tail.strip()


# main code here
if __name__ == '__main__':
    nih_data('Adams', 'Phil')
    