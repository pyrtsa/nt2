[{'functor': {'arity': '1',
              'call_types': [],
              'ret_arity': '0',
              'rturn': {'default': 'T'},
              'type_defs': [],
              'types': ['real_']},
  'unit': {'global_header': {'first_stamp': 'modified by jt the 04/12/2010',
                             'included': ['#include <nt2/include/functions/frexp.hpp>'],
                             'notes': [],
                             'stamp': 'modified by jt the 12/12/2010'},
           'ranges': {'real_': [['T(-10)', 'T(10)']]},
           'specific_values': {'default': {},
                               'real_': {'nt2::Inf<T>()': 'nt2::One<r_t>()',
                                         'nt2::Minf<T>()': 'nt2::Mone<r_t>()',
                                         'nt2::Mone<T>()': 'nt2::Mone<r_t>()',
                                         'nt2::One<T>()': 'nt2::One<r_t>()',
                                         'nt2::Zero<T>()': 'nt2::Zero<r_t>()'},
                               'signed_int_': {'nt2::Mone<T>()': 'nt2::Mone<r_t>()',
                                               'nt2::One<T>()': 'nt2::One<r_t>()',
                                               'nt2::Zero<T>()': 'nt2::Zero<r_t>()'},
                               'unsigned_int_': {'nt2::One<T>()': 'nt2::One<r_t>()',
                                                 'nt2::Zero<T>()': 'nt2::Zero<r_t>()'}},
           'verif_test': {'property_call': None,
                          'property_value': {'default': ['boost::fusion::get<0>(nt2::frexp(a0))*2']},
                          'ulp_thresh': '0'}},
  'version': '0.1'}]