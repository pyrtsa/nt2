<<<<<<< HEAD
[{'functor': {'arity': '2',
=======
[ ##script manually modified 
{'functor': {'arity': '2',
>>>>>>> functor2
              'call_types': ['T','iT'],
              'ret_arity': '0',
              'rturn': {'default': 'typename boost::result_of<nt2::meta::floating(T)>::type'},
              'type_defs': ['typedef int32_t iT;'],
              'types': ['real_'],#, 'unsigned_int_', 'signed_int_']
              },
  'unit': {'global_header': {'first_stamp': 'modified by jt the 08/12/2010',
                             'included': [],
                             'notes': [],
                             'stamp': 'modified by jt the 14/12/2010'},
           'ranges': {'real_': [['T(-10)', 'T(10)'], ['T(-10)', 'T(10)']],
                      'signed_int_': [['-100', '100'], ['-100', '100']],
                      'unsigned_int_': [['0', '100'], ['0', '100']]},
           'specific_values': {'default': {},
                               'real_': {'nt2::Inf<T>(),3': 'nt2::Inf<r_t>()',
                                         'nt2::Minf<T>(),3': 'nt2::Minf<r_t>()',
                                         'nt2::Mone<T>(),3': 'nt2::Mone<r_t>()',
                                         'nt2::Nan<T>(),3': 'nt2::Nan<r_t>()',
                                         'nt2::One<T>(),3': 'nt2::One<r_t>()',
                                         'nt2::Zero<T>(),3': 'nt2::Zero<r_t>()'},
                               'signed_int_': {'nt2::Mone<T>(),3': 'nt2::Mone<r_t>()',
                                               'nt2::One<T>(),3': 'nt2::One<r_t>()',
                                               'nt2::Zero<T>(),3': 'nt2::Zero<r_t>()'},
                               'unsigned_int_': {'nt2::One<T>(),3': 'nt2::One<r_t>()',
                                                 'nt2::Zero<T>(),3': 'nt2::Zero<r_t>()'}},
           'verif_test': {'property_call' : {'real_': ['nt2::powi(a0,nt2::Two<iT>())','nt2::powi(a0,nt2::Three<iT>())',], 'default' : []},
                          'property_value': {'real_': ['nt2::sqr(a0)','a0*nt2::sqr(a0)'],'default' : []},
                          'ulp_thresh': {'default': ['1','1']}}},
  'version': '0.1'}]
