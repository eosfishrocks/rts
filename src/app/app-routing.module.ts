import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import {MainComponent} from './pages/main/main.component';
import {VerifiedComponent} from './areas/verified/verified.component';
import {VoteComponent} from './areas/vote/vote.component';
import {PendingComponent} from './areas/pending/pending.component';
import {ReportComponent} from './areas/report/report.component';
import {AccountComponent} from './areas/account/account.component';
import {ArbitrationComponent} from './areas/arbitration/arbitration.component';

const routes: Routes = [
  {path: '', component: MainComponent,
    children: [
      {path: '', component: VerifiedComponent},
      {path: 'pending', component: PendingComponent},
      {path: 'report', component: ReportComponent},
      {path: 'account', component: AccountComponent},
      {path: 'arbiters', component: ArbitrationComponent},
      {path: 'vote', component: VoteComponent},
    ]
  },
  { path: '**', redirectTo: '404', pathMatch: 'full' }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
