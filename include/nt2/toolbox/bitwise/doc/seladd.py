[ ##script modified manually by jt
{
    'functor' : {       ## intrinsics values related to functor seladd
        'arity'         : '3',    ## functor number of parameters
        'ret_arity'     : '0',## must be '0' or omitted if not a tuple
        'types'         : ['real_', 'integer_'],     ## list of types string
        'simd_types'    : ['real_', 'integer_'],     ## list of types string
        'rturn'         : { 'default' :  'typename boost::result_of<nt2::meta::arithmetic(T,T)>::type' },     ## dictionary of return types
        'call_types'    : [],## types used in call ['T']*arity if omitted 
        'type_defs'     : [],  ## supplementary typedefs
        }, ## end of functor
    'unit'    : {       ## informations for creating unit tests
        'global_header' : { ## header of machin.cpp
            'first_stamp' : 'created  by $author$ the $date$', ## creation stamp
            'stamp'       : 'modified by $author$ the $date$', ## modification stamp
            'included'    : [],     ## list of supplementary include directives
            'notes'       : [],        ## list of strings that will be included in a
                                            ## global comment
            },
        'specific_values' : {
                'real_'       : {
                    'nt2::Inf<T>()' :  {'result' : 'nt2::Inf<r_t>()' ,'ulp_thresh':'0.5'},
                    'nt2::Minf<T>()':  {'result' : 'nt2::Minf<r_t>()' ,'ulp_thresh':'0.5'},
                    'nt2::Nan<T>()' :  {'result' : 'nt2::Nan<r_t>()' ,'ulp_thresh':'0.5'},
                    'nt2::Zero<T>()':  {'result' : 'nt2::Zero<r_t>()','ulp_thresh':'0.5'},
                    'T(0),T(1),T(2)':  {'result' : 'T(1)','ulp_thresh':'0.5'},
                    'T(25),T(1),T(2)':  {'result' : 'T(3)','ulp_thresh':'0.5'},
                },
                'signed_int_   ': {
                    'nt2::Zero<T>()': {'result' : 'nt2::Zero<r_t>()','ulp_thresh':'0.5'},
                    'T(0),T(1),T(2)':  {'result' : 'T(1)','ulp_thresh':'0.5'},
                    'T(25),T(1),T(2)':  {'result' : 'T(3)','ulp_thresh':'0.5'},
                 },
                'default': {
                    'nt2::Zero<T>()': {'result' : 'nt2::Zero<r_t>()','ulp_thresh':'0.5'},
                    'T(0),T(1),T(2)':  {'result' : 'T(1)','ulp_thresh':'0.5'},
                    'T(25),T(1),T(2)':  {'result' : 'T(3)','ulp_thresh':'0.5'},
                 },
           },  ## dictionary of parameters and values to be tested
        'ranges'          :  {
             'default'       : [[["T(0)","T(0)"],["T(-10000)","T(10000)"],["T(-10000)","T(10000)"]],
                                [["T(-1)","T(-1)"],["T(-10000)","T(10000)"],["T(-10000)","T(10000)"]]],
             'real_'       : [[["T(0)","T(0)"],["T(-10000)","T(10000)"],["T(-10000)","T(10000)"]],
                                [["nt2::Nan<T>()","nt2::Nan<T>()"],["T(-10000)","T(10000)"],["T(-10000)","T(10000)"]]],
              },  ## dictionary of ranges for random tests
        'verif_test'      : { ## verification dictionary
            'simd'            : {},   ## dictionary of translations for simd
            'property_call'   : {'integer_' : ['nt2::seladd(a0,a1,a2)'],},  ## dictionary of calls per types
            'property_value'  : {'integer_' : ['a0?a1+a2:a1'],}, ## dictionary of alternate calls
            'ulp_thresh'      : {'default' : ['0'],},     ## validity thresholds(s)
        },  ## end of verif_test
    },  ## end of unit 
},
]
