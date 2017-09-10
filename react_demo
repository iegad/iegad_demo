import React, { Component } from 'react';
import './App.css';


export class Page extends Component {
    constructor() {
        super();
        this.state = {
          name: ""
        }
        /* 很关键 */
        this.onHandlerClick = this.onHandlerClick.bind(this);
    }


    onHandlerClick(e) {
        this.setState({
          name: document.getElementById("txt-name").value
        });
    }


    render() {
        return (
          <div>
              <span>Hello, { this.state.name }</span>
              <br/>
              <a href="javascript:;" onClick={ this.onHandlerClick }>Click</a>
              <br/>
              <input type="text" id="txt-name"/>
          </div>
        );
    }
} 

