import { Component, OnInit } from '@angular/core';
import {Router} from '@angular/router';

@Component({
  selector: 'app-toolbar',
  templateUrl: './toolbar.component.html',
  styleUrls: ['./toolbar.component.sass']
})
export class ToolbarComponent implements OnInit {

  title: string;
  constructor(private router: Router) {}

  ngOnInit() {
    this.addTitle(this.getTitle());
  }

  addTitle(title: string) {
    this.title = title;
  }

  getTitle(): string {
    switch (this.router.url) {
      case '/':
        return 'Recent verified';
      case '/pending':
        return 'Recent pending';
      case '/arbiters':
        return 'Arbitration';
      case '/vote':
        return 'Vote';
    }
  }

  search() {}

}
