<<<<<<< HEAD
[{'functor': {'arity': '1',
=======
[##script manually modified
{'functor': {'arity': '1',
>>>>>>> functor2
              'call_types': [],
              'ret_arity': '0',
              'rturn': {'default': 'typename boost::result_of<nt2::meta::floating(T)>::type'},
              'type_defs': [],
              'types': ['real_', 'unsigned_int_', 'signed_int_']},
  'unit': {'global_header': {'first_stamp': 'modified by jt the 08/12/2010',
                             'included': ['#include <nt2/include/functions/log.hpp>',
<<<<<<< HEAD
                                          '#include <nt2/include/functions/sqr.hpp>'],
=======
                                          '#include <nt2/include/functions/sqr.hpp>',
                                          '#include <nt2/toolbox/crlibm/include/exp.hpp>'],
>>>>>>> functor2
                             'notes': [],
                             'stamp': 'modified by jt the 14/12/2010'},
           'ranges': {'real_': [['T(-10)', 'T(10)']],
                      'signed_int_': [['-10', '10']],
                      'unsigned_int_': [['0', '10']]},
<<<<<<< HEAD
           'specific_values': {'default': {},
                               'real_': {'nt2::Inf<T>()': 'nt2::Inf<r_t>()',
                                         'nt2::Minf<T>()': 'nt2::Zero<r_t>()',
                                         'nt2::Mone<T>()': 'nt2::One<r_t>()/nt2::Exp_1<r_t>()',
                                         'nt2::Nan<T>()': 'nt2::Nan<r_t>()',
                                         'nt2::One<T>()': 'nt2::Exp_1<r_t>()',
                                         'nt2::Zero<T>()': 'nt2::One<r_t>()'},
                               'signed_int_': {'nt2::Mone<T>()': 'nt2::One<r_t>()/nt2::Exp_1<r_t>()',
                                               'nt2::One<T>()': 'nt2::Exp_1<r_t>()',
                                               'nt2::Zero<T>()': 'nt2::One<r_t>()'},
                               'unsigned_int_': {'nt2::One<T>()': 'nt2::Exp_1<r_t>()',
                                                 'nt2::Zero<T>()': 'nt2::One<r_t>()'}},
           'verif_test': {'property_call': {'default': ['nt2::log(nt2::exp(a0))',
                                                        'nt2::sqr(nt2::exp(a0))']},
                          'property_value': {'default': ['T(a0)','nt2::exp(2*a0)']},
=======
           'specific_values': {
               'default': {},
               'real_': {
                   'nt2::Inf<T>()': {'result' : 'nt2::Inf<r_t>()','ulp_thresh':'0.75'},
                   'nt2::Minf<T>()': {'result' : 'nt2::Zero<r_t>()','ulp_thresh':'0.75'},
                   'nt2::Nan<T>()': {'result' : 'nt2::Nan<r_t>()','ulp_thresh':'0.75'},
                   'nt2::One<T>()': {'result' : 'nt2::Exp_1<r_t>()','ulp_thresh':'0.75'},
                   'nt2::Zero<T>()': {'result' : 'nt2::One<r_t>()','ulp_thresh':'0.75'},
                   'nt2::Mone<T>()': {'result' : 'nt2::One<r_t>()/nt2::Exp_1<r_t>()','ulp_thresh':'0.75'},
                   },
               'signed_int_': {
                   'nt2::Mone<T>()': {'result' : 'nt2::One<r_t>()/nt2::Exp_1<r_t>()','ulp_thresh':'0.75'},
                   'nt2::One<T>()': {'result' : 'nt2::Exp_1<r_t>()','ulp_thresh':'0.75'},
                   'nt2::Zero<T>()': {'result' : 'nt2::One<r_t>()','ulp_thresh':'0.75'}
                   },
               'unsigned_int_': {
                   'nt2::One<T>()': {'result' : 'nt2::Exp_1<r_t>()','ulp_thresh':'0.75'},
                   'nt2::Zero<T>()': {'result' : 'nt2::One<r_t>()','ulp_thresh':'0.75'},
                   }
               },
           'verif_test': {'property_call': {'default': ['nt2::exp(a0)',
                                                        'nt2::log(nt2::exp(a0))',
                                                        'nt2::sqr(nt2::exp(a0))']},
                          'property_value': {'default': ['nt2::crlibm::exp<nt2::rn>(a0)',
                                                         'T(a0)',
                                                         'nt2::exp(2*a0)']},
>>>>>>> functor2
                          'ulp_thresh': {'default': ['1.5','1.5']}}},
  'version': '0.1'}]
