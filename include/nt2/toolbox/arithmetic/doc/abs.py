[{'functor': {'arity': '1',
              'call_types': [],
              'ret_arity': '0',
<<<<<<< HEAD
              'rturn': {'default': 'T',
                        'signed_int_': 'typename nt2::meta::as_integer<T,unsigned>::type'},
=======
              'rturn': {'default': 'T'},
>>>>>>> functor2
              'type_defs': [],
              'types': ['real_', 'unsigned_int_', 'signed_int_']},
  'unit': {'global_header': {'first_stamp': 'modified by jt the 30/11/2010',
                             'included': ['#include<nt2/toolbox/standard/include/abs.hpp>'],
                             'notes': ['''for integer standard implementation produces double and there can be
                                          a loss in precision. This is not the case of nt2::abs that produces unsigned integer
                                          output for integer entries''',
                                       '''take care that if abs is called with floating types, YOU MUST use nt2::abs. If not
                                          the punishment is generally calling the wrong system abs function, that transforms your real in
                                          integer !'''],
                             'stamp': 'modified by jt the 13/12/2010'},
           'ranges': {'default': [['nt2::Valmin<T>()', 'nt2::Valmax<T>()']],
                      'real_': [['T(-100)', 'T(100)']],
                      'signed_int_': [['T(-100)', 'T(100)']],
                      'unsigned_int_': [['T(0)', 'T(100)']]},
           'specific_values': {'real_': {'nt2::Inf<T>()': 'nt2::Inf<T>()',
                                         'nt2::Minf<T>()': 'nt2::Inf<T>()',
                                         'nt2::Mone<T>()': 'nt2::One<T>()',
                                         'nt2::Nan<T>()': 'nt2::Nan<T>()',
                                         'nt2::One<T>()': 'nt2::One<T>()',
                                         'nt2::Zero<T>()': 'nt2::Zero<T>()'},
                               'signed_int_': {'nt2::Mone<T>()': 'nt2::One<T>()',
                                               'nt2::One<T>()': 'nt2::One<T>()',
                                               'nt2::Zero<T>()': 'nt2::Zero<T>()'},
                               'unsigned_int_': {'nt2::One<T>()': 'nt2::One<T>()',
                                                 'nt2::Zero<T>()': 'nt2::Zero<T>()'}},
           'verif_test': {'property_call': None,
                          'property_value': {'default': ['nt2::standard::abs(a0)']},
                          'ulp_thresh': {'default': ['0']}}},
  'version': '0.1'}]
