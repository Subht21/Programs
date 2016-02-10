# -*- coding: utf-8 -*-
"""
Created on Wed Feb 10 11:02:17 2016

File Name:
Description:   This function checks if a python module is available.
Author:        Subhash C Thakur

"""

import importlib


def is_module(name):
    """
    This function checks if a python module is available.

    Parameters
    ----------
    name : string
        Name of the module under inspection.

    Returns
    -------
    result : boolean
        True if the module is available. False otherwise.

    Example
    -------
    is_module('numpy')

    """
    module_spec = importlib.util.find_spec(name)
    found = module_spec is not None
    print(found)

module_name = 'numpy'
if __name__ == '__main__':
    is_module(module_name)
