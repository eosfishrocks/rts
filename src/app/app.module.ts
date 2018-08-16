import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import {BrowserAnimationsModule} from '@angular/platform-browser/animations';
import {MatButtonModule, MatCardModule, MatFormFieldModule, MatIconModule, MatInputModule, MatToolbarModule} from '@angular/material';
import { MainComponent } from './pages/main/main.component';
import { VerifiedComponent } from './areas/verified/verified.component';
import { PendingComponent } from './areas/pending/pending.component';
import { VoteComponent } from './areas/vote/vote.component';
import { ReportComponent } from './areas/report/report.component';
import { ArbitrationComponent } from './areas/arbitration/arbitration.component';
import { AccountComponent } from './areas/account/account.component';
import { ToolbarComponent } from './items/toolbar/toolbar.component';
import { ReportCardComponent } from './items/report-card/report-card.component';

@NgModule({
  declarations: [
    AppComponent,
    MainComponent,
    VerifiedComponent,
    PendingComponent,
    VoteComponent,
    ReportComponent,
    ArbitrationComponent,
    AccountComponent,
    ToolbarComponent,
    ReportCardComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    BrowserAnimationsModule,
    MatButtonModule,
    MatToolbarModule,
    MatIconModule,
    MatFormFieldModule,
    MatInputModule,
    MatCardModule,
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
