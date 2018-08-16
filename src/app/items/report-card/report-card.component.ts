import {Component, Input, OnInit} from '@angular/core';

@Component({
  selector: 'app-report-card',
  templateUrl: './report-card.component.html',
  styleUrls: ['./report-card.component.sass']
})
export class ReportCardComponent implements OnInit {

  @Input() data: any;
  constructor() { }

  ngOnInit() {
  }

}
