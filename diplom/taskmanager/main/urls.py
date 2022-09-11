
from django.urls import path
from . import views
from django.contrib.staticfiles.storage import staticfiles_storage
from django.urls import include, path
from django.views.generic.base import RedirectView
from django.conf import settings

urlpatterns = [

    path('', views.index,name='home'),
    path('matr', views.matr, name='matr'),
    path('comb', views.comb, name='comb'),
    path('gen', views.gen, name='gen'),
    path('palin', views.palin, name='palin'),
    path('digsumm', views.digsumm, name='digsumm'),
    path('chislo', views.chislo, name='chislo'),
    path('zadchisla', views.zadchisla, name='zadchisla'),
    path('zadmatr', views.zadmatr, name='zadmatr'),
    path('zadcomb', views.zadcomb, name='zadcomb'),
]
