import {defineComponent} from "vue"

import "./assets/css/index.scss"

export default defineComponent({

    setup() {

       return () => {
           return (
               <div id="app">
                   <router-view />
               </div>
           )
       }
    }
})