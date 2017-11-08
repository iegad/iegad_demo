"use strict"

import Vue from 'vue';
import axios from 'axios';


Vue.config.productionTip = false;

new Vue({
    el: '#app',

    data: {
        mod: '',
        func: '',
        own: '',
        content: '',
        info: ''
    }, // data;

    methods: {
        setDebugLog: function(e) {
            axios({
                method: 'get',
                url: 'http://localhost:8080/action/astroboy/getdebuglog',
                params: {
                    id: 100011
                }
            }).then(
                resp => {
                    console.log(resp);
                }
            ).catch(
                err => {
                    console.log(err);
                }
            );
        }
    } // methods;
});
