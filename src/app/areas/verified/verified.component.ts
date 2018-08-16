import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-verified',
  templateUrl: './verified.component.html',
  styleUrls: ['./verified.component.sass']
})
export class VerifiedComponent implements OnInit {

  mockData = [
    {
      id: 1,
      name: 'Tomas',
      network: 'network',
      email: 'tomas@gmail.com',
      aliases: {network: 'Tomas777'},
      submittedBy: 'submitted',
      result: false,
      proof: 'proof',
      comments: 'comments',
      votes: 'votes',
    },
    {
      id: 2,
      name: 'Jerry',
      network: 'network',
      email: 'jerry@gmail.com',
      aliases: {network: 'Jerry666'},
      submittedBy: 'submitted',
      result: false,
      proof: 'proof',
      comments: 'comments',
      votes: 'votes',
    }
  ];

  reports = this.mockData;
  constructor() { }

  ngOnInit() {
  }

}
