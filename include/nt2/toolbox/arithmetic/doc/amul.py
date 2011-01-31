[{'functor': {'arity': '3',
              'call_types': [],
              'ret_arity': '0',
              'rturn': {'default': 'typename boost::result_of<nt2::meta::arithmetic(T,T,T)>::type'},
              'type_defs': [],
              'types': ['real_', 'signed_int_', 'unsigned_int_']},
  'unit': {'global_header': {'first_stamp': 'modified by jt the 28/11/2010',
                             'included': [],
                             'notes': [''],
                             'stamp': 'modified by jt the 13/12/2010'},
           'ranges': {'default': [['nt2::Valmin<T>()', 'nt2::Valmax<T>()'],
                                  ['nt2::Valmin<T>()', 'nt2::Valmax<T>()'],
                                  ['nt2::Valmin<T>()', 'nt2::Valmax<T>()']],
                      'real_': [['T(-10)', 'T(10)'],
                                ['T(-10)', 'T(10)'],
                                ['T(-10)', 'T(10)']]},
           'specific_values': {'default': {},
                               'real_': {'1,2,3': '7',
                                         'nt2::Inf<T>()': 'nt2::Inf<T>()',
                                         'nt2::Minf<T>()': 'nt2::Nan<T>()',
                                         'nt2::Mone<T>()': 'nt2::Zero<T>()',
                                         'nt2::Nan<T>()': 'nt2::Nan<T>()',
                                         'nt2::One<T>()': 'nt2::Two<T>()',
                                         'nt2::Zero<T>()': 'nt2::Zero<T>()'},
                               'signed_int_': {'1,2,3': '7',
                                               'nt2::Mone<T>()': 'nt2::Zero<T>()',
                                               'nt2::One<T>()': 'nt2::Two<T>()',
                                               'nt2::Zero<T>()': 'nt2::Zero<T>()'},
                               'unsigned_int_': {'1,2,3': '7',
                                                 'nt2::One<T>()': 'nt2::Two<T>()',
                                                 'nt2::Zero<T>()': 'nt2::Zero<T>()'}},
           'verif_test': {'property_call': None,
                          'property_value': {'default': ['a0+a1*a2']},
                          'ulp_thresh': {'default': ['0']}}},
  'version': '0.1'}]