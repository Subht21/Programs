# -*- coding: utf-8 -*-
#!/usr/bin/python
"""
Created on Mon Feb  2  1:43:19 2016

File Name:     email_retriever.py
Description:   This program retrieves the email ids from a given web address.
Input:         Web url string
Output:        Array of email address
Author:        Subhash C Thakur

"""

import urllib.request
import re

emailregex = re.compile(r"\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,6}\b", 
                        re.IGNORECASE)

def email_retriever(url):

    print(url)
    page = urllib.request.urlopen(url).read()
    
    #print(page.decode('utf-8'))
    emails = set(re.findall(emailregex, page.decode('utf-8')))
    print(emails)

email_retriever('http://www.lokawiz.com')