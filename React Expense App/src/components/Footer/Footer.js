//importing libraries
import React from 'react';

//importing stylesheets
import classes from './Footer.module.css';

const Footer = ()=>{
    return(
        <div className={classes.footer}>
            <p>Built With <i class="fab fa-react"></i> By Rajeev Pandey</p>
        </div>
    );
}

export default Footer;