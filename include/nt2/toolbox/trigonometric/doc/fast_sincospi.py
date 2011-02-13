[ ##script manually modified 
{
    'functor' : {       ## intrinsics values related to functor fast_sincospi
        'arity'         : '1',    ## functor number of parameters
        'ret_arity'     : '2',## must be '0' or omitted if not a tuple
        'types'         : ['real_', 'unsigned_int_', 'signed_int_'],     ## list of types string
        'rturn'         : {'default' : 'boost::fusion::tuple<ftype,ftype>' },     ## ditionary of return types
        'call_types'    : [],## types used in call ['T']*arity if omitted 
        'type_defs'     : ["typedef typename boost::result_of<nt2::meta::floating(T)>::type ftype;"],  ## supplementary typedefs
        }, ## end of functor
    'unit'    : {       ## informations for creating unit tests
        'global_header' : { ## header of machin.cpp
            'first_stamp' : 'created  by $author$ the $date$', ## creation stamp
            'stamp'       : 'modified by $author$ the $date$', ## modification stamp
            'included'    : ['#include <nt2/toolbox/trigonometric/include/constants.hpp>',
                             '#include <nt2/include/functions/sinpi.hpp>',
                             '#include <nt2/include/functions/cospi.hpp>'],     ## list of supplementary include directives
            'notes'       : [],        ## list of strings that will be included in a
                                            ## global comment
            },
        'specific_values' : {
                'real_'       : {
                    'nt2::Inf<T>()' :     {'result' : ['nt2::Nan<r_t0>()']*2 ,'ulp_thresh':'0.75'},                              
                    'nt2::Minf<T>()':     {'result' : ['nt2::Nan<r_t0>()']*2 ,'ulp_thresh':'0.75'},                              
                    'nt2::Nan<T>()' :     {'result' : ['nt2::Nan<r_t0>()']*2 ,'ulp_thresh':'0.75'},                              
                    'nt2::Half<T>()':     {'result' : ['nt2::Nan<r_t0>()','nt2::Nan<r_t0>()'] ,'ulp_thresh':'0.75'},            
                    'nt2::Quarter<T>()':  {'result' : ['nt2::Sqrt_2o_2<r_t0>()']*2 ,'ulp_thresh':'0.75'},                        
                    'nt2::Mhalf<T>()':    {'result' : ['nt2::Nan<r_t0>()','nt2::Nan<r_t1>()'] ,'ulp_thresh':'0.75'},           
                    '-nt2::Quarter<T>()': {'result' : ['-nt2::Sqrt_2o_2<r_t0>()','nt2::Sqrt_2o_2<r_t0>()'] ,'ulp_thresh':'0.75'},
                    'nt2::Zero<T>()':     {'result' : ['nt2::Zero<r_t0>()','nt2::One<r_t0>()'],'ulp_thresh':'0.75'},             
                },
                'signed_int_   ': {
                    'nt2::Zero<T>()':  {'result' : ['nt2::Zero<r_t0>()','nt2::One<r_t0>()'],'ulp_thresh':'0.75'},  
                },
                'default': {
                    'nt2::Zero<T>()':  {'result' : ['nt2::Zero<r_t0>()','nt2::One<r_t0>()'],'ulp_thresh':'0.75'},  
                },
           },  ## dictionary of parameters and values to be tested
        'ranges'          :  {
             'default'       : [["T(0.25)","T(0.25)"]],
             'signed_int_'   : [["T(-40)","T(40)"]],
             'unsigned_int_' : [["T(0)","T(40)"]],
              },  ## dictionary of ranges for random tests
        'verif_test'      : { ## verification dictionary
            'property_call'   : {'real_' : ['nt2::fast_sincospi(a0)'],},  ## dictionary of calls per types
            'property_value'  : {'real_' : [['nt2::sinpi(a0)','nt2::cospi(a0)']],}, ## dictionary of alternate calls
            'ulp_thresh'      : {'real_' : ['0.5'],},     ## validity thresholds(s)
        },  ## end of verif_test
    },  ## end of unit 
},
]
