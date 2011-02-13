[ ##script manually modified by create_py_doc.py
{
    'functor' : {       ## intrinsics values related to functor acsc
        'arity'         : '1',    ## functor number of parameters
        'ret_arity'     : '0',## must be '0' or omitted if not a tuple
        'types'         : ['real_', 'unsigned_int_', 'signed_int_'],     ## list of types string
        'rturn'         : { 'default' : 'typename boost::result_of<nt2::meta::floating(T)>::type' },     ## ditionary of return types
        'call_types'    : [],## types used in call ['T']*arity if omitted 
        'type_defs'     : [],  ## supplementary typedefs
        }, ## end of functor
    'unit'    : {       ## informations for creating unit tests
        'global_header' : { ## header of machin.cpp
            'first_stamp' : 'created  by $author$ the $date$', ## creation stamp
            'stamp'       : 'modified by $author$ the $date$', ## modification stamp
            'included'    : ['#include <nt2/toolbox/trigonometric/include/constants.hpp>',
                             '#include <nt2/toolbox/crlibm/include/asin.hpp>',
                             '#include <nt2/include/functions/rec.hpp>'],     ## list of supplementary include directives
            'notes'       : ['asin(1/a0)'],        ## list of strings that will be included in a
                                            ## global comment
            },
        'specific_values' : {
                'real_'       : {
                    'nt2::Inf<T>()'  :  {'result' : 'nt2::Zero<r_t>()',  'ulp_thresh':'0.5'},
                    'nt2::Minf<T>()' :  {'result' : 'nt2::Zero<r_t>()',  'ulp_thresh':'0.5'},
                    'nt2::Nan<T>()'  :  {'result' : 'nt2::Nan<r_t>()',  'ulp_thresh':'0.5'},
                    'nt2::One<T>()'  :  {'result' : 'nt2::Pio_2<r_t>()', 'ulp_thresh':'0.5'},
                    'nt2::Two<T>()' :   {'result' : 'nt2::Pi<r_t>()/6', 'ulp_thresh':'0.5'},
                    'nt2::Mone<T>()' :  {'result' : '-nt2::Pio_2<r_t>()', 'ulp_thresh':'0.5'},
                    '-nt2::Two<T>()':   {'result' : '-nt2::Pi<r_t>()/6', 'ulp_thresh':'0.5'},
                    'nt2::Zero<T>()' :  {'result' : 'nt2::Nan<r_t>()', 'ulp_thresh':'0.5'},
                },
                'signed_int_   ': {
                    'nt2::Zero<T>()' :  {'result' : 'nt2::Nan<r_t>()', 'ulp_thresh':'0.5'},
                    'nt2::One<T>()'  :  {'result' : 'nt2::Pio_2<r_t>()', 'ulp_thresh':'0.5'},
                    'nt2::Mone<T>()' :  {'result' : '-nt2::Pio_2<r_t>()', 'ulp_thresh':'0.5'},
                    'nt2::Two<T>()' :   {'result' : 'nt2::Pi<r_t>()/6', 'ulp_thresh':'0.5'},
                    '-nt2::Two<T>()':   {'result' : '-nt2::Pi<r_t>()/6', 'ulp_thresh':'0.5'},
                },
                'default': {
                    'nt2::Zero<T>()':   {'result' : 'nt2::Nan<r_t>()', 'ulp_thresh':'0.5'},
                    'nt2::One<T>()' :   {'result' : 'nt2::Pio_2<r_t>()', 'ulp_thresh':'0.5'},
                },
           },  ## dictionary of parameters and values to be tested
        'ranges'          :  {
             'default'       : [["nt2::One<T>()","nt2::Ten<T>()"]],
             'real_'         : [["T(1.01)","nt2::Ten<T>()"]],
             'signed_int_'   : [["T(1)","T(10)"]],
              },  ## dictionary of ranges for random tests
        'verif_test'      : { ## verification dictionary
            'property_call'   : {'real_' : ['nt2::acsc(a0)'],},  ## dictionary of calls per types
            'property_value'  : {'real_' : ['nt2::crlibm::asin<nt2::rn>(nt2::rec(a0))'],}, ## dictionary of alternate calls
            'ulp_thresh'      : {'real_' : ['1.0'],},     ## validity thresholds(s)
        },  ## end of verif_test
    },  ## end of unit 
},
]